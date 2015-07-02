# The test scripts *.jobs have been converted using the regular expression
# mpirun -np (\d\d?) \./(ij|new_ij)\s(.*)\s> (.*)\.out\.(.*)\R
# with the replace pattern
# ADDTEST($4\.$5 $1 $2 "$3")\R
# in Eclipse.

# Default tests
ADDTEST(default.0 1 ij "-cljp -rlx 0 -xisone")
ADDTEST(default.1 2 ij "-P 1 1 2 -cljp -rlx 0 -xisone")
ADDTEST(default.2 3 ij "-P 1 1 3 -cljp -rlx 0 -xisone")

# Aggressive coarsening
#=============================================================================
# new_ij: Test aggressive coarsening interpolation options
#     1: 2s-ei interpolation 1 level (Pmx = 4)
#     2: 2s-std interpolation 1 level (Pmx = 4)
#     3: 2s-ext interpolation 1 level (tr = 0.3)
#     4: multipass interpolation 1 level
#     5: 2s-ei interpolation all levels (Pmx = 4)
#     6: 2s-std interpolation all levels (Pmx = 4)
#     7: 2s-ext interpolation all levels (tr = 0.3 P12_tr = 0.2)
#     8: multipass interpolation all levels
#     9: 2s-ei interpolation all levels (Pmx = 4, P12_mx = 3)
#     8: multipass interpolation all levels for systems problem unknown approach
#     8: 2s-ei interpolation all levels for systems problem unknown approach
#     8: multipass interpolation all levels for systems problem hybrid approach
#     8: 2s-ei interpolation all levels for systems problem hybrid approach
#=============================================================================
ADDTEST(agg_interp.1 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 1 -agg_interp 1 -agg_Pmx 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.2 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 1 -agg_interp 2 -agg_Pmx 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.3 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 1 -agg_interp 3 -agg_tr 0.3 -solver 1 -rlx 6")
ADDTEST(agg_interp.4 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 1 -agg_interp 4  -solver 1 -rlx 6")
ADDTEST(agg_interp.5 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 10 -agg_interp 1 -agg_Pmx 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.6 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 10 -agg_interp 2 -agg_Pmx 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.7 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 10 -agg_interp 3 -agg_tr 0.3 -agg_P12_tr 0.2 -solver 1 -rlx 6")
ADDTEST(agg_interp.8 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 10 -agg_interp 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.9 8 new_ij "-rhsrand -n 30 29 31 -P 2 2 2 -hmis -agg_nl 1 -agg_interp 1 -agg_Pmx 4 -agg_P12_mx 3 -solver 1 -rlx 6")
ADDTEST(agg_interp.10 8 new_ij "-rhsrand -n 20 19 22 -P 2 2 2 -sysL 3 -nf 3 -hmis -agg_nl 10 -agg_interp 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.11 8 new_ij "-rhsrand -n 20 19 22 -P 2 2 2 -sysL 3 -nf 3 -hmis -agg_nl 10 -agg_interp 1 -agg_Pmx 4 -agg_P12_mx 4 -solver 1 -rlx 6")
ADDTEST(agg_interp.12 8 new_ij "-rhsrand -n 20 19 22 -P 2 2 2 -sysL 3 -nf 3 -hmis -agg_nl 10 -agg_interp 4 -nodal 1 -solver 1 -rlx 6")
ADDTEST(agg_interp.13 8 new_ij "-rhsrand -n 20 19 22 -P 2 2 2 -sysL 3 -nf 3 -hmis -agg_nl 10 -agg_interp 1 -agg_Pmx 4 -agg_P12_mx 4 -nodal 1 -solver 1 -rlx 6")

# Coarsening
#=============================================================================
# ij: Run default case with different coarsenings, hybrid GS,
#    1: Cleary_LJP
#    2: parallel Ruge
#    3: Ruge 3rd pass
#    4: Falgout
# new_ij: Run default case with low complexity coarsenings, hybrid GS,
#    5: PMIS
#    6: HMIS
#    7: Falgout 2 levels aggressive coarsening
#    8: HMIS 1 level aggressive coarsening
#=============================================================================
ADDTEST(coarsening.1 4 ij "-rhsrand -n 15 15 10 -P 2 2 1 -cljp -27pt")
ADDTEST(coarsening.2 4 ij "-rhsrand -n 15 15 10 -P 2 2 1 -ruge -27pt")
ADDTEST(coarsening.3 4 ij "-rhsrand -n 15 15 10 -P 2 2 1 -ruge3c -gm -27pt")
ADDTEST(coarsening.4 4 ij "-rhsrand -n 15 15 10 -P 2 2 1 -falgout -27pt")
ADDTEST(coarsening.5 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -27pt")
ADDTEST(coarsening.6 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -hmis -27pt")
ADDTEST(coarsening.7 4 new_ij "-rhsrand -n 60 60 30 -P 2 2 1 -falgout -agg_nl 2 -27pt -rlx 6 -solver 1")
ADDTEST(coarsening.8 4 new_ij "-rhsrand -n 60 60 30 -P 2 2 1 -hmis -agg_nl 1 -27pt -rlx 6 -solver 1")
ADDTEST(coarsening.9 2 new_ij "-hmis -gm")

# Interpolation
#=============================================================================
# new_ij: Run default case with different interpolation operators
#    1: Extended interpolation
#    2: FF interpolation
#    3: standard interpolation
#    4: Extended interpolation and truncation max 4 elmts per row
#    5: FF interpolation and truncation max 4 elmts per row
#    6: standard interpolation and truncation max 4 elmts per row
#=============================================================================
ADDTEST(interp.1 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -interptype 6")
ADDTEST(interp.2 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -interptype 7")
ADDTEST(interp.3 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -interptype 8")
ADDTEST(interp.4 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -interptype 6 -Pmx 4")
ADDTEST(interp.5 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -interptype 7 -Pmx 4")
ADDTEST(interp.6 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -pmis -interptype 8 -Pmx 4")

#=============================================================================
# ij: LOBPCG cases
#=============================================================================
#ADDTEST(lobpcg.1 2 ij "-lobpcg -vrand 2 -seed 1 -tol 1.e-4 -vout 1") # lobpcg.out.vout.1
# use vectors computed by previous run as the initial
#ADDTEST(logpcg.2 2 ij "-lobpcg -vfromfile -seed 1") # lobpcg.out.vfromfile

#=============================================================================
# ij: tests different ways of generating IJMatrix
#=============================================================================
ADDTEST(matrix.0 2 ij "-rhsrand")
ADDTEST(matrix.1 2 ij "-rhsrand -exact_size")
ADDTEST(matrix.2 2 ij "-rhsrand -low_storage")
ADDTEST(matrix.3 4 new_ij "-fromfile A_tstoffd -rhsfromfile b_tstoffd")
ADDTEST(matrix.4 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -add 1")
ADDTEST(matrix.5 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -add 1 -off_proc 1")
ADDTEST(matrix.6 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -off_proc 1")
ADDTEST(matrix.7 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -off_proc 1 -omp 1")
ADDTEST(matrix.8 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -off_proc 1 -omp 1 -add 1")
ADDTEST(matrix.9 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -omp 1 -exact_size")
ADDTEST(matrix.10 2 new_ij "-test_ij -solver 2 -max_iter 5 -chunk 1 -omp 1")

#=============================================================================
# ij driver for eigenvalue solvers: 
# This script tests LOBPCG input options and defaults 
#===========================================================================

# All default parameters
ADDTEST(options.default  2 ij " -lobpcg -seed 1")
#-solver none : no HYPRE preconditioner is used  (default -solver 1)
ADDTEST(options.solver.none  2 ij " -lobpcg -solver none -seed 1")
# maximum number of LOBPCG iterations (default 100)
ADDTEST(options.itr.100 2 ij " -lobpcg -n 15 15 16 -vrand 2 -solver 2 -seed 1")# 2 iterations maximum
ADDTEST(options.itr.2 2 ij " -lobpcg -n 15 15 16 -vrand 2 -solver 2 -seed 1 -itr 2")
# -vrand 2 : compute 2 eigenpairs using random initial vectors (default 1)
ADDTEST(options.vrand.2 2 ij "-lobpcg -vrand 2 -seed 1")
#-seed 1  : use 1 as the seed for the pseudo-random number generator
#           (default seed is based on the time of the run)
# The output files below should be identical, but different from options.out.default
ADDTEST(options.seed 2 ij "-lobpcg -seed 1")
ADDTEST(options.seed.repeat 2 ij "-lobpcg -seed 1")
#no orthonormality check
ADDTEST(options.no_orthchk 2 ij " -lobpcg -seed 1          ")
#-orthchk : check eigenvectors for orthonormality
ADDTEST(options.orthchk 2 ij " -lobpcg -seed 1 -orthchk ")
#-verb 0  : no print
ADDTEST(options.verb.0 2 ij " -lobpcg -seed 1 -verb 0")
#-verb 1  : print initial eigenvalues and residuals, iteration number, number of
#          non-convergent eigenpairs and final eigenvalues and residuals (default)
ADDTEST(options.verb.1 2 ij " -lobpcg -seed 1        ")
#-verb 2  : print eigenvalues and residuals on each iteration
ADDTEST(options.verb.2 2 ij " -lobpcg -seed 1 -verb 2")
#-pcgitr 0 : the preconditioner is applied directly
ADDTEST(options.pcgitr.0 2 ij " -lobpcg -seed 1 -pcgitr 0")
#default number of inner iterations (1)
ADDTEST(options.pcgitr.1 2 ij " -lobpcg -seed 1          ")
#-pcgitr 2 : two inner iterations
ADDTEST(options.pcgitr.2 2 ij " -lobpcg -seed 1 -pcgitr 2")
#default residual tolerance for inner iterations (0.01)
ADDTEST(options.pcgtol.01 2 ij " -lobpcg -solver 2 -seed 1 -pcgitr 1000")
#-pcgtol 0.05
ADDTEST(options.pcgtol.05 2 ij " -lobpcg -solver 2 -seed 1 -pcgitr 1000 -pcgtol 0.05")
# -gen : generalized eigenvalue problem; A = B
ADDTEST(options.gen.1 2 ij " -lobpcg -gen -seed 1 -orthchk")
# A: anizotropic Laplacian (cx = 0.1, cy = 1, cz = 10), B: Laplacian
ADDTEST(options.gen.2 2 ij " -lobpcg -gen -seed 1 -c 0.1 1 10 -orthchk")

#=============================================================================
# ij: Run default case with different coarsenings, hybrid GS,
#    1: hybrid SOR on 3 procs
#    2: hybrid scaled symGS on 4 procs. with scaled opt. outer wt on fine level
#    3: hybrid GS on 4 procs with backward solve GS on up cycle
#    4: hybrid GS, no CF-relaxation, on 4 procs
#    5: hybrid SOR on 4 procs, determine a weight automatically
#    6: use Schwarz smoothing
#    7: use Schwarz smoothing with automatic weight determination
#    8: use 3 level Schwarz smoothing with automatic weight determination
#       followed by SSOR with automatic weight determination
#=============================================================================
ADDTEST(smoother.0 3 new_ij "-rhsrand -n 15 30 10 -w 1.1 -owl 1.0 0")
ADDTEST(smoother.1 4 new_ij "-rhsrand -n 15 15 10 -P 2 2 1 -rlx 6 -owl -10 0")
ADDTEST(smoother.2 4 new_ij "-rhsrand -n 20 20 10 -P 2 2 1 -rlx_up 4")
ADDTEST(smoother.3 4 new_ij "-rhsrand -n 20 20 10 -P 2 2 1 -CF 0")
ADDTEST(smoother.4 4 new_ij "-rhsrand -solver 1 -rlx 6 -n 20 20 10 -P 2 2 1 -CF 0-w -10")
ADDTEST(smoother.5 4 new_ij "-rhsrand -solver 1 -rlx 6 -n 20 20 10 -P 2 2 1-sysL 2 -nf 2 -smlv 1 -smtype 6 -dom 1 -ov 0 -var 1")
ADDTEST(smoother.6 4 new_ij "-rhsrand -solver 1 -rlx 6 -n 20 20 10 -P 2 2 1-sysL 2 -nf 2 -smlv 1 -smtype 6 -dom 1 -ov 0 -var 1 -ow -10 -sw -10")
ADDTEST(smoother.7 4 new_ij "-rlx 6 -n 20 20 10 -P 2 2 1 -sysL 3 -nf 3 -smlv 3-smtype 6 -dom 1 -ov 0 -w -10 -sw -10")

#=============================================================================
# ij: Run default case with different solvers
#    1: BoomerAMG_PCG
#    2: DS_PCG
#    3: BoomerAMG_GMRES
#    4: DS_GMRES
#    5: BoomerAMG_CGNR
#    6: DS_CGNR
#    7: PILUT_GMRES
#    8: ParaSails_PCG
#   20: Hybrid_PCG
#
# lobpcg: Run default case with all available PCG preconditioners
#    1: BoomerAMG_PCG
#    2: DS_PCG
#    8: ParaSails_PCG
#   12: Schwarz_PCG
#   43: Euclid_PCG
#
# new_ij: test systems AMG
#	  unknown approach
#	  hybrid approach with block smoother
# 	  nodal approach
#       more solvers:
#        51: BoomerAMG_LGMRES
#        50: DS_LGMRES
#        61: BoomerAMG_FlexGMRES
#        60: DS_FlexGMRES
#
#=============================================================================

ADDTEST(solvers.0 2 ij "-solver 1 -rhsrand")
ADDTEST(solvers.1 2 ij "-solver 2 -rhsrand")
ADDTEST(solvers.2 2 ij "-solver 3 -rhsrand")
ADDTEST(solvers.3 2 ij "-solver 4 -rhsrand")
ADDTEST(solvers.4 2 ij "-solver 5 -rhsrand -w 0.67 -ns 2")
ADDTEST(solvers.5 2 ij "-solver 6 -rhsrand")
ADDTEST(solvers.6 2 ij "-solver 7 -rhsrand")
ADDTEST(solvers.7 2 ij "-solver 8 -rhsrand")
ADDTEST(solvers.8 2 ij "-solver 20 -rhsrand")
ADDTEST(solvers.9 2 ij "-solver 20 -cf 0.5 -rhsrand")
ADDTEST(solvers.10 2 ij "-solver 20 -cf 0.5 -rhsrand -solver_type 2")
ADDTEST(solvers.11 2 ij "-solver 20 -cf 0.5 -rhsrand -solver_type 3")


#PCG run ...LOBPCG run for one eigenpair...LOBPCG for 5 eigenpairs
ADDTEST(solvers.1.lobpcg 2 ij "-solver 1 -tol 1.e-6 ")
ADDTEST(solvers.1.lobpcg.1 2 ij "-lobpcg -solver 1 -tol 1.e-6 -pcgitr 0 -seed 1 -vrand 1")
ADDTEST(solvers.1.lobpcg.5 2 ij "-lobpcg -solver 1 -tol 1.e-6 -pcgitr 0  -seed 1 -vrand 5")

#PCG run ...LOBPCG run for one eigenpair...LOBPCG for 5 eigenpairs
ADDTEST(solvers.2.lobpcg 2 ij "-solver 2 -tol 1.e-6 ")
ADDTEST(solvers.2.lobpcg.1 2 ij "-lobpcg -solver 2 -tol 1.e-6  -pcgitr 20 -seed 1 -vrand 1")
ADDTEST(solvers.2.lobpcg.5 2 ij "-lobpcg -solver 2 -tol 1.e-6  -pcgitr 20 -seed 1 -vrand 5")

#PCG run ...LOBPCG run for one eigenpair...LOBPCG for 5 eigenpairs
ADDTEST(solvers.8.lobpcg 2 ij "-solver 8 -tol 1.e-6 ")
ADDTEST(solvers.8.lobpcg.1 2 ij "-lobpcg -solver 8 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1")
ADDTEST(solvers.8.lobpcg.5 2 ij "-lobpcg -solver 8 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 5")

#PCG run ...LOBPCG run for one eigenpair...LOBPCG for 5 eigenpairs
ADDTEST(solvers.12.lobpcg 2 ij "-solver 12 -tol 1.e-6 ")
ADDTEST(solvers.12.lobpcg.1 2 ij "-lobpcg -solver 12 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1")
ADDTEST(solvers.12.lobpcg.5 2 ij "-lobpcg -solver 12 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 5")

#PCG run ...LOBPCG run for one eigenpair...LOBPCG for 5 eigenpairs
ADDTEST(solvers.43.lobpcg 2 ij "-solver 43 -tol 1.e-6 ")
ADDTEST(solvers.43.lobpcg.1 2 ij "-lobpcg -solver 43 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1")
ADDTEST(solvers.43.lobpcg.5 2 ij "-lobpcg -solver 43 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 5")

#systems AMG run ...unknown approach, hybrid approach, nodal approach
ADDTEST(solvers.sysu 2 new_ij "-n 20 20 20 -sysL 2 -nf 2")
ADDTEST(solvers.sysh 2 new_ij "-n 20 20 20 -sysL 2 -nf 2 -nodal 1 -smtype 6 -smlv 10 -dom 1 -ov 0")
ADDTEST(solvers.sysn 2 new_ij "-n 20 20 20 -sysL 2 -nf 2 -interptype 10")

#LGMRS and FlexGMRES
ADDTEST(solvers.101 2 new_ij "-solver 50 -rhsrand")
ADDTEST(solvers.102 2 new_ij "-solver 51 -rhsrand")
ADDTEST(solvers.103 2 new_ij "-solver 60 -rhsrand")
ADDTEST(solvers.104 2 new_ij "-solver 61 -rhsrand")

#agglomerated coarse grid solve
ADDTEST(solvers.105 8 new_ij "-n 80 80 80 -P 2 2 2 -agg_nl 1 -hmis -interptype 6 -Pmx 4 -seq_th 100 -solver 1 -rlx 6")
ADDTEST(solvers.107 8 new_ij "-n 40 40 40 -P 2 2 2 -agg_nl 1 -hmis -interptype 6 -Pmx 4 -seq_th 100 -solver 1 -rlx 6 -sysL 3 -nf 3")

#redundant coarse grid solve
ADDTEST(solvers.106 8 new_ij "-n 80 80 80 -P 2 2 2 -agg_nl 1 -hmis -interptype 6 -Pmx 4 -seq_th 100 -solver 1 -rlx 6 -red 1")
ADDTEST(solvers.108 8 new_ij "-n 40 40 40 -P 2 2 2 -agg_nl 1 -hmis -interptype 6 -Pmx 4 -seq_th 100 -solver 1 -rlx 6 -sysL 3 -nf 3 -red 1")
