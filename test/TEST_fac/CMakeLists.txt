# Expr: mpirun -np (\d\d?) \./(sstruct_fac)\s(.*)\s*>\s*(.*)\.out\.(.*)
# Replace: ADDTEST($4\.$5 $1 $2 "$3")

#=============================================================================
# sstruct_fac: test suites for FAC solver.
#=============================================================================
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
    FILES_MATCHING PATTERN "*lev*.in")
ADDTEST(sstruct_fac.0 1 sstruct_fac "-in 3lev.in -solver 99 -r 2 1 1")
ADDTEST(sstruct_fac.1 2 sstruct_fac "-in 3lev.in -solver 99 -P 2 1 1")

# RDF: There is something wrong with the FAC code; these currently don't work
#ADDTEST(sstruct_fac.2 1 sstruct_fac "-in 3lev_multibox.in -solver 99 -r 2 3 1")
#ADDTEST(sstruct_fac.3 6 sstruct_fac "-in 3lev_multibox.in -solver 99 -P 2 3 1")

ADDTEST(sstruct_fac.4 1 sstruct_fac "-in 4lev.in -solver 99 -r 1 2 2")
ADDTEST(sstruct_fac.5 4 sstruct_fac "-in 4lev.in -solver 99 -P 1 2 2")

ADDTEST(sstruct_fac.6 1 sstruct_fac "-in 5lev.in -solver 99 -r 1 5 1")
ADDTEST(sstruct_fac.7 5 sstruct_fac "-in 5lev.in -solver 99 -P 1 5 1")

ADDTEST(sstruct_fac.8 1 sstruct_fac "-in 6lev.in -solver 99 -r 2 1 2")
ADDTEST(sstruct_fac.9 4 sstruct_fac "-in 6lev.in -solver 99 -P 2 1 2")

ADDTEST(sstruct_fac.10 1 sstruct_fac "-in 7lev.in -solver 99 -r 1 1 2")
ADDTEST(sstruct_fac.11 2 sstruct_fac "-in 7lev.in -solver 99 -P 1 1 2")