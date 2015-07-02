# The test scripts *.jobs have been converted using the regular expression
# mpirun -np (\d\d?) \./(ams_driver)\s(.*)\s> (.*)\.out\.(.*)\R
# with the replace pattern
# ADDTEST(ams_$4\.$5 $1 $2 "$3")\R
# in Eclipse.
# See TEST_* subfolders.

#=============================================================================
# ams: Run through solvers
#=============================================================================
ADDTEST(ams_solvers.0 4 ams_driver "-solver 2")
ADDTEST(ams_solvers.1 4 ams_driver "-solver 2 -coord")
ADDTEST(ams_solvers.2 4 ams_driver "-solver 2 -h1")
ADDTEST(ams_solvers.3 4 ams_driver "-solver 2 -h1 -coord")
ADDTEST(ams_solvers.4 4 ams_driver "-solver 3")
ADDTEST(ams_solvers.5 4 ams_driver "-solver 3 -coord")
ADDTEST(ams_solvers.6 4 ams_driver "-solver 3 -h1")
ADDTEST(ams_solvers.7 4 ams_driver "-solver 3 -h1 -coord")
ADDTEST(ams_solvers.8 4 ams_driver "-solver 5 -tol 1e-4")
ADDTEST(ams_solvers.9 4 ams_driver "-solver 5 -tol 1e-4 -coord")
ADDTEST(ams_solvers.10 4 ams_driver "-solver 5 -tol 1e-4 -h1")
ADDTEST(ams_solvers.11 4 ams_driver "-solver 5 -tol 1e-4 -h1 -coord")
ADDTEST(ams_solvers.12 4 ams_driver "-solver 3 -type 13 -amgrlx 6 -agg 1 -itype 6 -pmax 4 -ctype 10 -tol 0 -zc -maxit 18 -rr 4")
