# mpirun -np (\d\d?) \./(fei)\s(.*)\s*>\s*(.*)\.out\.(.*)
# ADDTEST(fei_$4\.$5 $1 $2 "$3")

#=============================================================================
# fei: Run through solvers
#=============================================================================
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
ADDTEST(fei_solvers.0 4 fei "-solver 0 ")
ADDTEST(fei_solvers.1 4 fei "-solver 1 ")
ADDTEST(fei_solvers.2 4 fei "-solver 2 ")
ADDTEST(fei_solvers.3 4 fei "-solver 3 ")
ADDTEST(fei_solvers.4 4 fei "-solver 4 ")
ADDTEST(fei_solvers.5 4 fei "-solver 5 ")
ADDTEST(fei_solvers.6 4 fei "-solver 6 ")
ADDTEST(fei_solvers.7 4 fei "-solver 7 ")