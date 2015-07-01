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

add_executable (ij ij.c)
target_link_libraries (ij hypre ${HYPRE_LIBS})
 
add_executable (ij_mv ij_mv.c)
target_link_libraries (ij_mv hypre ${HYPRE_LIBS})
 
add_executable (new_ij new_ij.c)
target_link_libraries (new_ij hypre ${HYPRE_LIBS})
 
add_executable (sstruct sstruct.c)
target_link_libraries (sstruct hypre ${HYPRE_LIBS})
 
add_executable (struct struct.c)
target_link_libraries (struct hypre ${HYPRE_LIBS})
 
add_executable (ams_driver ams_driver.c)
target_link_libraries (ams_driver hypre ${HYPRE_LIBS})

add_executable (maxwell_unscaled maxwell_unscaled.c)
target_link_libraries (maxwell_unscaled hypre ${HYPRE_LIBS})
 
add_executable (sstruct_fac sstruct_fac.c)
target_link_libraries (sstruct_fac hypre ${HYPRE_LIBS})