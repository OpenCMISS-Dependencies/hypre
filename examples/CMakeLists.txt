set(EXAMPLE_SRCS ex1.c ex10.cxx ex11.c ex12.c ex12f.f
    ex13.c ex14.c ex15.c ex15big.c ex16.c ex17.c ex18.c ex18comp.c
    ex2.c ex3.c ex4.c ex5.c ex5big.c
    ex5f.f ex6.c ex7.c ex8.c ex9.c
)
# Babel-related examples
# ex5b.c ex5b77.f ex5b90.f90 ex5bj.java ex5bp.py ex5bxx.cxx ex6b.c ex6b77.f
# Some MESH writing, but not even build by the original script: vis.c

foreach(SRC ${EXAMPLE_SRCS})
    get_filename_component(FNAME ${SRC} NAME_WE)
    add_executable(${FNAME} ${SRC})
    target_link_libraries(${FNAME} hypre)
    if (UNIX)
        target_link_libraries(${FNAME} m)
    endif()
endforeach()