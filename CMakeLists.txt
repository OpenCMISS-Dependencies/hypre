cmake_minimum_required (VERSION 3.0)
project (HYPRE VERSION 2.9.0 LANGUAGES C Fortran)

option(BUILD_TESTS "${PROJECT_NAME} - Build tests" ON)

# Configuration options
option(HYPRE_SHARED               "Build a shared library" OFF)
option(HYPRE_BIGINT               "Use long long int for HYPRE_Int" OFF)
option(HYPRE_SEQUENTIAL           "Compile without MPI" OFF)
option(HYPRE_TIMING               "Use HYPRE timing routines" OFF)
#option(HYPRE_USING_HYPRE_BLAS     "Use internal BLAS library" OFF)
#option(HYPRE_USING_HYPRE_LAPACK   "Use internal LAPACK library" OFF)
option(HYPRE_NO_GLOBAL_PARTITION  "Use assumed partition" OFF)
option(HYPRE_PRINT_ERRORS         "Print HYPRE errors" OFF)
option(HYPRE_USING_OPENMP         "Use OpenMP" ON)
option(HYPRE_USING_FEI            "Use FEI" OFF)

if (HYPRE_BIGINT)
  set (HYPRE_USING_FEI OFF CACHE BOOL "" FORCE)
  # In the future, also turn off babel
endif ()

#   --with-examples         Build example codes.
#   --with-fei              Use internal FEI routines.
#   --with-superlu          Use internal SuperLU routines.
#   --with-mli              Use MLI

find_package(BLAS ${BLAS_VERSION} REQUIRED)
find_package(LAPACK ${LAPACK_VERSION} REQUIRED)
if (NOT HYPRE_SEQUENTIAL)
  find_package(MPI REQUIRED)
  SET(CMAKE_C_COMPILER ${MPI_C_COMPILER})
  SET(CMAKE_Fortran_COMPILER ${MPI_Fortran_COMPILER})
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
configure_file (
  "${PROJECT_SOURCE_DIR}/config/HYPRE_config.h.cmake.in"
  "${PROJECT_BINARY_DIR}/HYPRE_config.h"
  )

# Exported the long source and header collection to separate file
include(./CollectSources.cmake)

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

# Set library build type
if (HYPRE_SHARED)
  set (BUILD_SHARED_LIBS ON CACHE INTERNAL "" FORCE)
else ()
  set (BUILD_SHARED_LIBS OFF CACHE INTERNAL "" FORCE)
endif ()

# Set MPI compile flags (done by compiler wrapper!)
#if (NOT HYPRE_SEQUENTIAL)
#  if ((MPI_C_FOUND) AND (NOT CMAKE_C_COMPILER STREQUAL MPI_C_COMPILER))
#    include_directories (${MPI_C_INCLUDE_PATH})
#    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MPI_C_COMPILE_FLAGS}")
#  endif ()
#  if ((MPI_CXX_FOUND) AND (NOT CMAKE_CXX_COMPILER STREQUAL MPI_CXX_COMPILER))
#    include_directories (${MPI_CXX_INCLUDE_PATH})
#    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MPI_CXX_COMPILE_FLAGS}")
#  endif ()
#endif()

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
target_link_libraries(hypre PUBLIC blas lapack)

install(TARGETS hypre EXPORT hypre-config
    DESTINATION lib
    INCLUDES DESTINATION include/hypre)
install(EXPORT hypre-config DESTINATION lib/cmake)   
include(CMakePackageConfigHelpers)
WRITE_BASIC_PACKAGE_VERSION_FILE(${CMAKE_CURRENT_BINARY_DIR}/hypre-config-version.cmake
    COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/hypre-config-version.cmake DESTINATION lib/cmake)
install(FILES ${HYPRE_HEADERS} ${PROJECT_BINARY_DIR}/HYPRE_config.h DESTINATION include/hypre)

if (BUILD_TESTS)
    add_subdirectory (test)
endif()