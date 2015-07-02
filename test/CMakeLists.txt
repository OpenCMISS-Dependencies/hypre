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

if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# First entry: exec name, following: source files
# Seems redundant as the shipped tests involving more than one source file DO NOT WORK.
set(TEST1 struct struct)
set(TEST2 sstruct sstruct)
set(TEST3 ij ij)
set(TEST4 ij_mv ij_mv)
set(TEST5 new_ij new_ij)
set(TEST6 ams_driver ams_driver)
set(TEST9 maxwell_unscaled maxwell_unscaled)
set(TEST10 sstruct_fac sstruct_fac)
set(TEST11 zboxloop zboxloop)
# Copy C to CXX source
configure_file(ij.c ${CMAKE_CURRENT_BINARY_DIR}/cxx_ij.cpp COPYONLY)
configure_file(sstruct.c ${CMAKE_CURRENT_BINARY_DIR}/cxx_sstruct.cpp COPYONLY)
configure_file(struct.c ${CMAKE_CURRENT_BINARY_DIR}/cxx_struct.cpp COPYONLY)
set(TEST12 cxx_ij ${CMAKE_CURRENT_BINARY_DIR}/cxx_ij.cpp)
set(TEST13 cxx_sstruct ${CMAKE_CURRENT_BINARY_DIR}/cxx_sstruct.cpp)
set(TEST14 cxx_struct ${CMAKE_CURRENT_BINARY_DIR}/cxx_struct.cpp)
set(TEST15 f77_struct f77_struct.f)
set(TEST16 f77_ij f77_ij.f)
set(TEST17 f77_ij_mv f77_ij_mv.f)
set(NUMTESTS 17)
if (HYPRE_USING_FEI)
    set(TEST18 fei fei)
    set(NUMTESTS 18)
endif()
# These are all contained in the makefile, but are not build by any
# of the all, all77 and all++ targets; i presume they are NOT WORKING / INCOMPLETE
#set(TEST12 test_ij hypre_set_precond test_ij)
#set(TEST16 driver_commpkg driver_commpkg)
#set(TEST1 struct_for fstruct_mv.f fstruct_ls.f)#struct_for.f
#set(TEST2 ex1_for fstruct_mv.f fstruct_ls.f ex1_for)
#set(TEST3 ex3_for fstruct_mv.f fstruct_ls.f ex3_for)
#set(TEST4 ex5_for fij_mv.f fparcsr_mv.f fparcsr_ls.f ex5_for.c)
#set(TEST5 ex6_for fstruct_mv.f fstruct_ls.f fsstruct_mv.f fsstruct_ls.f ex6_for)
#set(TEST6 ex7_for fstruct_mv.f fstruct_ls.f fsstruct_mv.f fsstruct_ls.f ex7_for)
#set(TEST7 for_maxwell fparcsr_mv.f fsstruct_mv.f fsstruct_ls.f for_maxwell)

foreach(IDX RANGE 1 ${NUMTESTS})
    if (TEST${IDX})
        set(_TMP ${TEST${IDX}})
        list(GET _TMP 0 EXEC_NAME)
        list(REMOVE_AT _TMP 0)
        add_executable(${EXEC_NAME} ${_TMP})
        target_link_libraries (${EXEC_NAME} hypre ${HYPRE_LIBS})
        target_compile_definitions(${EXEC_NAME} PRIVATE HYPRE_TIMING HYPRE_FORTRAN)
    endif() 
endforeach()

# The test scripts *.jobs have been converted using the regular expressions
# See TEST_* subfolders for details
add_executable(helper argumenthelper.c)

set(TESTRUNNER ${CMAKE_CURRENT_SOURCE_DIR}/TestRunner.cmake)
macro(ADDTEST NAME NPROC TARGET ARGS)
    message(STATUS "Called ADDTEST from ${CMAKE_CURRENT_BINARY_DIR}")
    #if (_DO_)
    add_test(NAME ${NAME}
     COMMAND ${CMAKE_COMMAND} 
    -DMPIEXEC=${MPIEXEC}
    #-DMPIEXEC=$<TARGET_FILE:helper>
    -DNPFLAG:STRING=${MPIEXEC_NUMPROC_FLAG}
    -DNPROC=${NPROC}
    -DEXEC=$<TARGET_FILE:${TARGET}>
    -DARGS:STRING=${ARGS}
    -DOUT=${NAME}.out
    -DWD=${CMAKE_CURRENT_BINARY_DIR}
    -P ${TESTRUNNER}
    )
    #endif()
endmacro()
#add_subdirectory(TEST_ij)
#add_subdirectory(TEST_ams)
add_subdirectory(TEST_fac)
if (HYPRE_USING_FEI)
    #add_subdirectory(TEST_fei)
endif()