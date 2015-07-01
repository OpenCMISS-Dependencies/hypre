cmake_minimum_required (VERSION 3.0)
project(HYPRE VERSION 2.10.0b LANGUAGES C Fortran)

option(BUILD_TESTS "${PROJECT_NAME} - Build tests" ON)
set(PACKAGE_CONFIG_DIR "lib/cmake" CACHE STRING "Directory for package config files (relative to CMAKE_INSTALL_PREFIX)")

# Configuration options
option(HYPRE_BIGINT               "Use long long int for HYPRE_Int" OFF)
option(HYPRE_SEQUENTIAL           "Compile without MPI" OFF)
option(HYPRE_TIMING               "Use HYPRE timing routines" OFF)
option(HYPRE_NO_GLOBAL_PARTITION  "Use assumed partition" OFF)
option(HYPRE_PRINT_ERRORS         "Print HYPRE errors" OFF)
# Slight interface change to accomodate with OpenCMISS standard
option(WITH_OPENMP "${PROJECT_NAME} - Use OpenMP" ON)
SET(HYPRE_USING_OPENMP ${WITH_OPENMP})
option(HYPRE_USING_FEI            "Use FEI" OFF)

if (HYPRE_BIGINT)
  set (HYPRE_USING_FEI OFF CACHE BOOL "" FORCE)
  # In the future, also turn off babel
endif ()

if (HYPRE_SEQUENTIAL)
  set (HYPRE_NO_GLOBAL_PARTITION OFF CACHE BOOL "" FORCE)
endif ()

#   --with-examples         Build example codes.
#   --with-fei              Use internal FEI routines.
#   --with-superlu          Use internal SuperLU routines.
#   --with-mli              Use MLI

find_package(BLAS ${BLAS_VERSION} REQUIRED)
find_package(LAPACK ${LAPACK_VERSION} REQUIRED)
if (NOT HYPRE_SEQUENTIAL)
  find_package(MPI REQUIRED)
  if (MPI_C_COMPILER)
      SET(CMAKE_C_COMPILER ${MPI_C_COMPILER})
      SET(CMAKE_Fortran_COMPILER ${MPI_Fortran_COMPILER})
  else()
      include_directories(${MPI_C_INCLUDE_PATH} ${MPI_Fortran_INCLUDE_PATH})
  endif()
  include(CheckSymbolExists)
  SET(CMAKE_REQUIRED_INCLUDES ${MPI_C_INCLUDE_PATH} ${MPI_Fortran_INCLUDE_PATH})
  CHECK_SYMBOL_EXISTS(MPI_Comm_f2c mpi.h HYPRE_HAVE_MPI_COMM_F2C)
endif()

# Set OpenMP compile flags
if (HYPRE_USING_OPENMP)
  find_package(OpenMP)
  if (OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${OpenMP_Fortran_FLAGS}")
  else()
    SET(HYPRE_USING_OPENMP FALSE)
  endif()
endif()

# Configure a header file to pass CMake settings to the source code
configure_file(
  "${PROJECT_SOURCE_DIR}/config/HYPRE_config.h.cmake.in"
  "${PROJECT_BINARY_DIR}/HYPRE_config.h"
  )

# Exported the long source and header collection to separate file
include(./CollectSources.cmake)

# Fortran mangling - new CMake scheme
include(FortranCInterface)
FortranCInterface_HEADER(${CMAKE_CURRENT_BINARY_DIR}/HYPRE_FC.h
    MACRO_NAMESPACE "HYPRE_FMANGLE_")
LIST(APPEND HYPRE_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/HYPRE_FC.h)

include_directories(${HYPRE_SOURCE_DIR})
include_directories(${HYPRE_BINARY_DIR})
include_directories(utilities)
include_directories(multivector)
include_directories(krylov)
include_directories(seq_mv)
include_directories(parcsr_mv)
include_directories(parcsr_block_mv)
include_directories(distributed_matrix)
include_directories(IJ_mv)
include_directories(matrix_matrix)
include_directories(distributed_ls)
include_directories(distributed_ls/Euclid)
include_directories(distributed_ls/ParaSails)
include_directories(parcsr_ls)
include_directories(struct_mv)
include_directories(struct_ls)
include_directories(sstruct_mv)
include_directories(sstruct_ls)

# Turn optimization off for this file
#set_source_files_properties (lapack/dlamch.c PROPERTIES COMPILE_FLAGS -O0)

if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

if (HYPRE_USING_FEI)
  add_subdirectory(FEI_mv)
endif ()

add_library(hypre ${HYPRE_SOURCES} ${FEI_LIBS})
set_target_properties(hypre PROPERTIES OUTPUT_NAME hypre-${HYPRE_VERSION})
target_link_libraries(hypre PUBLIC blas lapack ${MPI_C_LIBRARIES})

install(TARGETS hypre EXPORT hypre-config
    DESTINATION lib
    INCLUDES DESTINATION include/hypre)
install(EXPORT hypre-config DESTINATION ${PACKAGE_CONFIG_DIR})   
install(FILES ${HYPRE_HEADERS} ${PROJECT_BINARY_DIR}/HYPRE_config.h DESTINATION include/hypre)
include(CMakePackageConfigHelpers)
WRITE_BASIC_PACKAGE_VERSION_FILE(${CMAKE_CURRENT_BINARY_DIR}/hypre-config-version.cmake
    COMPATIBILITY AnyNewerVersion)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-dependencies.cmake 
    "include(CMakeFindDependencyMacro)\r\n"
	"set(${PROJECT_NAME}_IMPORT_PREFIX \${_IMPORT_PREFIX})\r\n"
)
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-dependencies.cmake "find_dependency(BLAS ${BLAS_VERSION})\r\n")
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-dependencies.cmake "find_dependency(LAPACK ${LAPACK_VERSION})\r\n")
if (WITH_OPENMP)
    file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-dependencies.cmake "find_dependency(OpenMP)\r\n")
endif()
file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-dependencies.cmake "set(_IMPORT_PREFIX \${${PROJECT_NAME}_IMPORT_PREFIX})")
install(FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-version.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-dependencies.cmake
    DESTINATION ${PACKAGE_CONFIG_DIR})

if (BUILD_TESTS)
    add_subdirectory(test)
endif()