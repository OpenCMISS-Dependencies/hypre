# Link libraries
set (HYPRE_LIBS )
if (UNIX)
  list (APPEND HYPRE_LIBS m)
endif()

# CDEFS = -DHYPRE_TIMING -DHYPRE_FORTRAN
# CXXDEFS = -DNOFEI -DHYPRE_TIMING -DMPICH_SKIP_MPICXX
# -lstdc++ -lm

# Set MPI compile flags
if (NOT HYPRE_SEQUENTIAL)
    list (APPEND HYPRE_LIBS ${MPI_C_LIBRARIES})
endif()

add_definitions (-DHYPRE_TIMING)

if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

set(TEST_DRIVERS_C
    ij ij_mv new_ij sstruct struct 
    ams_driver maxwell_unscaled sstruct_fac
    ex1_for ex3_for ex5_for ex6_for ex7_for
    for_maxwell ij_b sstruct_b struct_b)
if (HYPRE_USING_FEI)
    list(APPEND TEST_DRIVERS_C fei) #fei_lscore
endif()    
foreach(_SRC ${TEST_DRIVERS_C})
    add_executable(${_SRC} ${_SRC})
    target_link_libraries (${_SRC} hypre ${HYPRE_LIBS})
endforeach()