#=============================================================================
# struct: Run CG+PFMG with skip base 3d case
#=============================================================================

ADDTEST(struct_cgpfmg3d.0 1 struct "-n 12 12 12 -solver 11 -skip 1  ")
#=============================================================================
# struct: Run CG+PFMG with skip parallel and blocking 
#=============================================================================

ADDTEST(struct_cgpfmg3d.1 8 struct "-n 3 3 3 -b 2 2 2 -P 2 2 2  -solver 11 -skip 1  ")

#=============================================================================
# Test solvers with some processors having no data
#=============================================================================

# SMG
ADDTEST(struct_emptyproc.00a 4 struct "-n 12 12 12 -P 2 1 2 -solver 0 ")
ADDTEST(struct_emptyproc.00a.a 6 struct "-n 12 12 12 -P 2 1 2 -solver 0 ")
ADDTEST(struct_emptyproc.00a.b 7 struct "-n 6 6 6 -b 2 2 2 -P 2 1 2 -solver 0 ")

# PFMG
ADDTEST(struct_emptyproc.01a 4 struct "-n 12 12 12 -P 2 2 1 -solver 1 ")
ADDTEST(struct_emptyproc.01a.a 6 struct "-n 12 12 12 -P 2 2 1 -solver 1 ")
ADDTEST(struct_emptyproc.01a.b 7 struct "-n 6 6 6 -b 2 2 2 -P 2 2 1 -solver 1 ")
# non-Galerkin
ADDTEST(struct_emptyproc.01b 4 struct "-n 12 12 12 -P 2 2 1 -rap 1 -skip 1 -relax 2 -solver 1 ")
ADDTEST(struct_emptyproc.01b.a 7 struct "-n 12 12 12 -P 2 2 1 -rap 1 -skip 1 -relax 2 -solver 1 ")

# PFMG constant 3
ADDTEST(struct_emptyproc.03a 4 struct "-n 12 12 12 -P 2 2 1 -solver 3 ")
ADDTEST(struct_emptyproc.03a.a 6 struct "-n 12 12 12 -P 2 2 1 -solver 3 ")
ADDTEST(struct_emptyproc.03a.b 7 struct "-n 6 6 6 -b 2 2 2 -P 2 2 1 -solver 3 ")
# non-Galerkin
ADDTEST(struct_emptyproc.03b 4 struct "-n 12 12 12 -P 2 2 1 -rap 1 -skip 1 -relax 2 -solver 3 ")
ADDTEST(struct_emptyproc.03b.a 7 struct "-n 12 12 12 -P 2 2 1 -rap 1 -skip 1 -relax 2 -solver 3 ")

# PFMG constant 4
ADDTEST(struct_emptyproc.04a 4 struct "-n 12 12 12 -P 2 2 1 -solver 4 ")
ADDTEST(struct_emptyproc.04a.a 6 struct "-n 12 12 12 -P 2 2 1 -solver 4 ")
ADDTEST(struct_emptyproc.04a.b 7 struct "-n 6 6 6 -b 2 2 2 -P 2 2 1 -solver 4 ")
# non-Galerkin
ADDTEST(struct_emptyproc.04b 4 struct "-n 12 12 12 -P 2 2 1 -rap 1 -skip 1 -relax 2 -solver 4 ")
ADDTEST(struct_emptyproc.04b.a 7 struct "-n 12 12 12 -P 2 2 1 -rap 1 -skip 1 -relax 2 -solver 4 ")

# PFMG-CG
ADDTEST(struct_emptyproc.11a 4 struct "-n 12 12 12 -P 2 2 1 -solver 11 ")
ADDTEST(struct_emptyproc.11a.a 7 struct "-n 12 12 12 -P 2 2 1 -solver 11 ")

# PFMG-CG constant 3
ADDTEST(struct_emptyproc.13a 4 struct "-n 12 12 12 -P 2 2 1 -solver 13 ")
ADDTEST(struct_emptyproc.13a.a 7 struct "-n 12 12 12 -P 2 2 1 -solver 13 ")

# PFMG-CG constant 4
ADDTEST(struct_emptyproc.14a 4 struct "-n 12 12 12 -P 2 2 1 -solver 14 ")
ADDTEST(struct_emptyproc.14a.a 7 struct "-n 12 12 12 -P 2 2 1 -solver 14 ")

# Jacobi-CG
ADDTEST(struct_emptyproc.17a 4 struct "-n 10 10 10 -P 1 2 2 -solver 17 ")
ADDTEST(struct_emptyproc.17a.a 7 struct "-n 10 10 10 -P 1 2 2 -solver 17 ")

# DS-CG
ADDTEST(struct_emptyproc.18a 4 struct "-n 11 11 11 -P 1 2 2 -solver 18 ")
ADDTEST(struct_emptyproc.18a.a 7 struct "-n 11 11 11 -P 1 2 2 -solver 18 ")

# Hybrid PFMG
ADDTEST(struct_emptyproc.21a 4 struct "-n 10 10 10 -P 1 2 2 -solver 21 ")
ADDTEST(struct_emptyproc.21a.a 7 struct "-n 10 10 10 -P 1 2 2 -solver 21 ")

# PFMG-GMRES
ADDTEST(struct_emptyproc.31a 4 struct "-n 11 11 11 -P 2 2 1 -solver 31 ")
ADDTEST(struct_emptyproc.31a.a 7 struct "-n 11 11 11 -P 2 2 1 -solver 31 ")

# PFMG-BiCGSTAB
ADDTEST(struct_emptyproc.41a 4 struct "-n 11 11 11 -P 2 2 1 -solver 41 ")
ADDTEST(struct_emptyproc.41a.a 7 struct "-n 11 11 11 -P 2 2 1 -solver 41 ")

# PFMG-LGMRES
ADDTEST(struct_emptyproc.51a 4 struct "-n 11 11 11 -P 2 2 1 -solver 51 ")
ADDTEST(struct_emptyproc.51a.a 7 struct "-n 11 11 11 -P 2 2 1 -solver 51 ")

# PFMG-FlexGMRES
ADDTEST(struct_emptyproc.61a 4 struct "-n 11 11 11 -P 2 2 1 -solver 61 ")
ADDTEST(struct_emptyproc.61a.a 7 struct "-n 11 11 11 -P 2 2 1 -solver 61 ")

#=============================================================================
# struct: Run Hybrid without the switch
#=============================================================================

ADDTEST(struct_hybrid.0 1 struct "-P 1 1 1 -solver 20 ")
ADDTEST(struct_hybrid.1 1 struct "-P 1 1 1 -solver 21 ")
ADDTEST(struct_hybrid.2 1 struct "-P 1 1 1 -solver 25 ")
ADDTEST(struct_hybrid.3 1 struct "-P 1 1 1 -solver 20 -solver_type 2 -cf 0.5 ")
ADDTEST(struct_hybrid.4 1 struct "-P 1 1 1 -solver 21 -solver_type 2 -cf 0.5 ")

#=============================================================================
# struct: Run Hybrid with the switch
#=============================================================================

ADDTEST(struct_hybridswitch.0 1 struct "-n 30 30 30 -P 1 1 1 -solver 20 ")
ADDTEST(struct_hybridswitch.1 1 struct "-n 30 30 30 -P 1 1 1 -solver 21 ")
ADDTEST(struct_hybridswitch.2 1 struct "-n 30 30 30 -P 1 1 1 -solver 25 ")
ADDTEST(struct_hybridswitch.3 3 struct "-P 1 1 3 -solver 30  ")
ADDTEST(struct_hybridswitch.4 3 struct "-P 1 3 1 -solver 31  ")
ADDTEST(struct_hybridswitch.5 3 struct "-P 3 1 1 -solver 37  ")
ADDTEST(struct_hybridswitch.6 1 struct "-P 1 1 1 -solver 38  ")
ADDTEST(struct_hybridswitch.7 1 struct "-P 1 1 1 -solver 39  ")

#=============================================================================
# struct: Run base 3d case
#=============================================================================

ADDTEST(struct_parflow.0 1 struct "-n 16 16 16 -c 2.0 3.0 40 -solver 1 -p 16 16 0  ")

#=============================================================================
# struct: Run parallel and blocking 
#=============================================================================

ADDTEST(struct_parflow.1 8 struct "-n 8 8 8 -P 2 2 2  -c 2.0 3.0 40 -solver 1 -p 16 16 0  ")
ADDTEST(struct_parflow.2 8 struct "-n 4 4 4 -b 2 2 2 -P 2 2 2  -c 2.0 3.0 40 -solver 1  -p 16 16 0 ")

#=============================================================================
# struct: Run base 2d case
#=============================================================================

ADDTEST(struct_parflow.3 1 struct "-d 2 -n 80 80 1 -solver 1   ")

#=============================================================================
# struct: Run parallel and blocking 
#=============================================================================

ADDTEST(struct_parflow.4 8 struct "-d 2 -n 10 80 1 -P 8 1 1 -solver 1  ")
ADDTEST(struct_parflow.5 4 struct "-d 2 -n 10 10 1 -b 4 4 1 -P 2 2 1 -solver 1  ")

#=============================================================================
# Check PFMG for power-of-two and non-power-of-two systems
#=============================================================================

# power-of-two

ADDTEST(struct_periodic.10 1 struct "-n 16 16 16 -p 16 16 0 -P 1 1 1 -solver 1 ")
ADDTEST(struct_periodic.11 2 struct "-n  8 16 16 -p 16 16 0 -P 2 1 1 -solver 1 ")
ADDTEST(struct_periodic.12 4 struct "-n  8  8 16 -p 16 16 0 -P 2 2 1 -solver 1 ")
ADDTEST(struct_periodic.13 4 struct "-n 16  8  8 -p 16 16 0 -P 1 2 2 -solver 1 ")

ADDTEST(struct_periodic.20 1 struct "-n 16 16 16 -p 16 0 16 -P 1 1 1 -skip 1 -rap 1 -solver 1 ")
ADDTEST(struct_periodic.21 2 struct "-n  8 16 16 -p 16 0 16 -P 2 1 1 -skip 1 -rap 1 -solver 1 ")

# non-power-of-two

ADDTEST(struct_periodic.30 1 struct "-n 20 20 20 -p  0 20 20 -P 1 1 1 -solver 1 ")
ADDTEST(struct_periodic.31 2 struct "-n 10 20 20 -p  0 20 20 -P 2 1 1 -solver 1 ")
ADDTEST(struct_periodic.32 4 struct "-n 10 20 10 -p  0 20 20 -P 2 1 2 -solver 1 ")
ADDTEST(struct_periodic.33 4 struct "-n 20 10 10 -p  0 20 20 -P 1 2 2 -solver 1 ")

ADDTEST(struct_periodic.40 1 struct "-n 20 20 20 -p  20 0 20 -P 1 1 1 -skip 1 -rap 1 -solver 1 ")
ADDTEST(struct_periodic.41 2 struct "-n 20 20 10 -p  20 0 20 -P 1 1 2 -skip 1 -rap 1 -solver 1 ")

#=============================================================================
# Check SMG for power-of-two systems
#=============================================================================

# power-of-two

ADDTEST(struct_periodic.50 1 struct "-n 16 16 16 -p 16 0 16 -P 1 1 1 -solver 0 ")
ADDTEST(struct_periodic.51 2 struct "-n  8 16 16 -p 16 0 16 -P 2 1 1 -solver 0 ")
ADDTEST(struct_periodic.52 4 struct "-n  8  8 16 -p 16 0 16 -P 2 2 1 -solver 0 ")
ADDTEST(struct_periodic.53 4 struct "-n 16  8  8 -p 16 0 16 -P 1 2 2 -solver 0 ")

#=============================================================================
# struct: Run PFMG 1d run as 2d and 3d
#=============================================================================

ADDTEST(struct_pfmgbase1d.0 1 struct "-n 12 1 1  -c 1 0 0 -d 2 -solver 1  ")
ADDTEST(struct_pfmgbase1d.1 2 struct "-n 2 1 1 -P 2 1 1 -b 3 1 1 -c 1 0 0 -solver 1  ")

#=============================================================================
# struct: Run PFMG base "true" 2d case
#=============================================================================

ADDTEST(struct_pfmgbase2d.0 1 struct "-n 12 12 1  -d 2 -solver 1 -relax 1  ")

#=============================================================================
# struct: Run PFMG parallel and blocking 
#=============================================================================

ADDTEST(struct_pfmgbase2d.1 3 struct "-n 4 12 1 -P 3 1 1 -d 2 -solver 1 -relax 1  ")
ADDTEST(struct_pfmgbase2d.2 3 struct "-n 4 4 1 -P 1 3 1 -b 3 1 1 -d 2 -solver 1 -relax 1  ")

#=============================================================================
# struct: Run PFMG 2d run as 3d
#=============================================================================

ADDTEST(struct_pfmgbase2d.3 4 struct "-n 3 1 12 -P 4 1 1 -c 1 0 1 -solver 1 -relax 1  ")
ADDTEST(struct_pfmgbase2d.4 2 struct "-n 1 12 6 -P 1 1 2 -c 0 1 1 -solver 1 -relax 1  ")
ADDTEST(struct_pfmgbase2d.5 3 struct "-n 12 4 1 -P 1 3 1 -c 1 1 0 -solver 1 -relax 1  ")

#=============================================================================
# struct: Run PFMG base 3d case
#=============================================================================

ADDTEST(struct_pfmgbase3d.0 1 struct "-n 12 12 12 -c 2.0 3.0 40 -solver 1  ")

#=============================================================================
# struct: Run PFMG parallel and blocking 
#=============================================================================

ADDTEST(struct_pfmgbase3d.1 8 struct "-n 6 6 6 -P 2 2 2  -c 2.0 3.0 40 -solver 1  ")
ADDTEST(struct_pfmgbase3d.2 4 struct "-n 3 12 12 -P 4 1 1 -c 2.0 3.0 40 -solver 1  ")
ADDTEST(struct_pfmgbase3d.3 4 struct "-n 12 3 12 -P 1 4 1 -c 2.0 3.0 40 -solver 1  ")
ADDTEST(struct_pfmgbase3d.4 4 struct "-n 12 12 3 -P 1 1 4 -c 2.0 3.0 40 -solver 1  ")
ADDTEST(struct_pfmgbase3d.5 1 struct "-n 3 4 3 -b 4 3 4  -c 2.0 3.0 40 -solver 1  ")
ADDTEST(struct_pfmgbase3d.6 8 struct "-n 3 3 3 -b 2 2 2 -P 2 2 2  -c 2.0 3.0 40 -solver 1  ")
ADDTEST(struct_pfmgbase3d.7 1 struct "-n 6 6 6 -b 2 2 2  -c 2.0 3.0 40 -solver 1  ")

#=============================================================================
# Make sure that the constant case and variable diag case give the same results
#=============================================================================

#2D
ADDTEST(struct_pfmgconstcoeffmp.10 1 struct "-d 2 -n 15 15 1 -istart -7 -7 0 -solver 3 -skip 1 -rap 1          ")
ADDTEST(struct_pfmgconstcoeffmp.11 1 struct "-d 2 -n 15 15 1 -istart -7 -7 0 -solver 4 -skip 1 -rap 1          ")
ADDTEST(struct_pfmgconstcoeffmp.12 1 struct "-d 2 -n 15 15 1 -istart -7 -7 0 -solver 3 -skip 1 -rap 1 -relax 2 ")
ADDTEST(struct_pfmgconstcoeffmp.13 1 struct "-d 2 -n 15 15 1 -istart -7 -7 0 -solver 4 -skip 1 -rap 1 -relax 2 ")

# 3D
ADDTEST(struct_pfmgconstcoeffmp.20 1 struct "-n 15 15 15 -istart -7 -7 -7 -solver 3 -skip 1 -rap 1          ")
ADDTEST(struct_pfmgconstcoeffmp.21 1 struct "-n 15 15 15 -istart -7 -7 -7 -solver 4 -skip 1 -rap 1          ")
ADDTEST(struct_pfmgconstcoeffmp.22 1 struct "-n 15 15 15 -istart -7 -7 -7 -solver 3 -skip 1 -rap 1 -relax 2 ")
ADDTEST(struct_pfmgconstcoeffmp.23 1 struct "-n 15 15 15 -istart -7 -7 -7 -solver 4 -skip 1 -rap 1 -relax 2 ")

#=============================================================================
# Make sure that serial vs parallel give the same results
#=============================================================================

ADDTEST(struct_pfmgconstcoeffmp.30 1 struct "-n 20 20 20 -P 1 1 1 -solver 3 -skip 1 -rap 1 ")
ADDTEST(struct_pfmgconstcoeffmp.31 2 struct "-n 10 20 20 -P 2 1 1 -solver 3 -skip 1 -rap 1 ")
ADDTEST(struct_pfmgconstcoeffmp.32 1 struct "-n 20 20 20 -P 1 1 1 -solver 3                ")
ADDTEST(struct_pfmgconstcoeffmp.33 2 struct "-n 10 20 20 -P 2 1 1 -solver 3                ")
ADDTEST(struct_pfmgconstcoeffmp.34 1 struct "-n 20 20 20 -P 1 1 1 -solver 3 -relax 2       ")
ADDTEST(struct_pfmgconstcoeffmp.35 2 struct "-n 10 20 20 -P 2 1 1 -solver 3 -relax 2       ")

ADDTEST(struct_pfmgconstcoeffmp.40 1 struct "-n 20 20 20 -P 1 1 1 -solver 4 -skip 1 -rap 1 ")
ADDTEST(struct_pfmgconstcoeffmp.41 2 struct "-n 10 20 20 -P 2 1 1 -solver 4 -skip 1 -rap 1 ")
ADDTEST(struct_pfmgconstcoeffmp.42 1 struct "-n 20 20 20 -P 1 1 1 -solver 4                ")
ADDTEST(struct_pfmgconstcoeffmp.43 2 struct "-n 10 20 20 -P 2 1 1 -solver 4                ")
ADDTEST(struct_pfmgconstcoeffmp.44 1 struct "-n 20 20 20 -P 1 1 1 -solver 4 -relax 2       ")
ADDTEST(struct_pfmgconstcoeffmp.45 2 struct "-n 10 20 20 -P 2 1 1 -solver 4 -relax 2       ")

#=============================================================================
# struct: Run PFMG 1d solve of the same problem in different orientations
#=============================================================================

ADDTEST(struct_pfmgorient.0 1 struct "-n 10 10 10 -c 1 1 256 -solver 1  ")
ADDTEST(struct_pfmgorient.1 1 struct "-n 10 10 10 -c 1 256 1 -solver 1  ")
ADDTEST(struct_pfmgorient.2 1 struct "-n 10 10 10 -c 256 1 1 -solver 1  ")

#=============================================================================
# struct: Run PFMG 1d run as 2d and 3d in different configurations.
#=============================================================================

ADDTEST(struct_pfmgtest1d.0 1 struct "-n 1 12 1  -c 0 1 0 -d 2 -solver 1  ")
ADDTEST(struct_pfmgtest1d.1 3 struct "-n 1 2 1 -P 1 3 1 -b 1 2 1 -c 0 1 0 -solver 1  ")
ADDTEST(struct_pfmgtest1d.2 4 struct "-n 1 1 3 -P 1 1 4  -c 0 0 1 -solver 1  ")

#=============================================================================
# struct: Run PFMG V(1,0) and V(0,1) cycles.
#=============================================================================

ADDTEST(struct_pfmgvcycle.0 3 struct "-P 1 1 3 -v 1 0 -solver 1  ")
ADDTEST(struct_pfmgvcycle.1 3 struct "-P 1 1 3 -v 0 1 -solver 1  ")


#=============================================================================
# struct: Run Periodic SMG base 3d case
#=============================================================================

ADDTEST(struct_psmgbase3d.0 1 struct "-n 8 8 8 -p 0 8 8 -solver 0  ")

#=============================================================================
# struct: Run Periodic SMG parallel and blocking 
#=============================================================================

ADDTEST(struct_psmgbase3d.1 1 struct "-n 4 4 4 -P 1 1 1  -p 0 8 8 -b 2 2 2 -solver 0  ")
ADDTEST(struct_psmgbase3d.2 4 struct "-n 2 8 8 -P 4 1 1  -p 0 8 8 -solver 0  ")
ADDTEST(struct_psmgbase3d.3 4 struct "-n 8 2 8 -P 1 4 1  -p 0 8 8 -solver 0  ")
ADDTEST(struct_psmgbase3d.4 4 struct "-n 8 8 2 -P 1 1 4  -p 0 8 8 -solver 0  ")

#=============================================================================
# struct: Run Periodic SMG base 3d case (periodic in x), test parallel 
# and blocking, and run a full periodic case. 
# Note: driver sets up right hand size for full periodic case that 
# satifies compatibility condition, it (the rhs) is dependent on blocking 
# and parallel partitioning. Thus results will differ with number of 
# blocks and processors.
#=============================================================================

ADDTEST(struct_psmgtest3d.0 1 struct "-n 8 8 8 -p 8 0 0 -solver 0  ")
ADDTEST(struct_psmgtest3d.1 8 struct "-n 2 2 2 -P 2 2 2  -p 8 0 0 -b 2 2 2 -solver 0  ")
ADDTEST(struct_psmgtest3d.2 4 struct "-n 4 8 4 -P 2 1 2  -p 8 8 8 -solver 0  ")


#=============================================================================
# struct: Test 1d run as 2d and 3d
#=============================================================================

ADDTEST(struct_smgbase1d.0 1 struct "-n 12 1 1  -c 1 0 0 -d 2 -solver 0  ")
ADDTEST(struct_smgbase1d.1 2 struct "-n 2 1 1 -P 2 1 1 -b 3 1 1 -c 1 0 0 -solver 0  ")


#=============================================================================
# struct: Run base "true" 2d case
#=============================================================================

ADDTEST(struct_smgbase2d.0  1 struct "-n 12 12 1 -d 2 -solver 0  ")

#=============================================================================
# struct: Test parallel and blocking 
#=============================================================================

ADDTEST(struct_smgbase2d.1 3 struct "-n 4 12 1 -P 3 1 1 -d 2 -solver 0  ")
ADDTEST(struct_smgbase2d.2 3 struct "-n 4 4 1 -P 1 3 1 -b 3 1 1 -d 2 -solver 0  ")
ADDTEST(struct_smgbase2d.3 4 struct "-n 3 1 12 -P 4 1 1 -c 1 0 1 -solver 0  ")
ADDTEST(struct_smgbase2d.4 2 struct "-n 1 12 6 -P 1 1 2 -c 0 1 1 -solver 0  ")


#=============================================================================
# struct: Run base 3d case
#=============================================================================

ADDTEST(struct_smgbase3d.0  1 struct "-n 12 12 12 -c 2.0 3.0 40 -solver 0 ")

#=============================================================================
# struct: Test parallel and blocking 
#=============================================================================

ADDTEST(struct_smgbase3d.1 8 struct "-n 6 6 6 -P 2 2 2  -c 2.0 3.0 40 -solver 0  ")
ADDTEST(struct_smgbase3d.2 4 struct "-n 3 12 12 -P 4 1 1 -c 2.0 3.0 40 -solver 0  ")
ADDTEST(struct_smgbase3d.3 4 struct "-n 12 3 12 -P 1 4 1 -c 2.0 3.0 40 -solver 0  ")
ADDTEST(struct_smgbase3d.4 4 struct "-n 12 12 3 -P 1 1 4 -c 2.0 3.0 40 -solver 0  ")
ADDTEST(struct_smgbase3d.5 1 struct "-n 6 6 6 -b 2 2 2  -c 2.0 3.0 40 -solver 0  ")

#=============================================================================
# struct: Test 1d run as 2d and 3d in different configurations.
#=============================================================================

ADDTEST(struct_smgtest1d.0 1 struct "-n 1 12 1  -c 0 1 0 -d 2 -solver 0  ")
ADDTEST(struct_smgtest1d.1 3 struct "-n 1 2 1 -P 1 3 1 -b 1 2 1 -c 0 1 0 -solver 0  ")
ADDTEST(struct_smgtest1d.2 4 struct "-n 1 1 3 -P 1 1 4  -c 0 0 1 -solver 0  ")

#=============================================================================
# struct: Test V(1,0) cycle.
#=============================================================================

ADDTEST(struct_smgvcycle.0 3 struct "-P 1 1 3 -v 1 0 -solver 0 ")

#=============================================================================
# struct: Run SMG-CG, PFMG-CG, DSCG, CG, and Hybrid.
#=============================================================================

ADDTEST(struct_solvers.0 3 struct "-P 1 1 3 -solver 10 ")
ADDTEST(struct_solvers.1 3 struct "-P 1 3 1 -solver 11 ")
ADDTEST(struct_solvers.2 3 struct "-P 3 1 1 -solver 17 ")
ADDTEST(struct_solvers.3 1 struct "-P 1 1 1 -solver 18 ")
ADDTEST(struct_solvers.4 1 struct "-P 1 1 1 -solver 19 ")


#=============================================================================
# Run default case with all available PCG preconditioners (solvers): 
#    10: SMG (default)
#    11: PFMG
#    17: 2-step Jacobi
#    18: Diagonal scaling
#    19: none
#=============================================================================

# PCG run... LOBPCG with one eigenpair .... LOBPCG with 5 eigenpairs
ADDTEST(struct_solvers.10.lobpcg 2 struct "-solver 10 -tol 1.e-6 ")
ADDTEST(struct_solvers.10.lobpcg.1 2 struct "-lobpcg -solver 10 -tol 1.e-6 -pcgitr 0 -seed 1 -vrand 1 ")
ADDTEST(struct_solvers.10.lobpcg.5 2 struct "-lobpcg -solver 10 -tol 1.e-6 -pcgitr 0  -seed 1 -vrand 5  ")

# PCG run... LOBPCG with one eigenpair .... LOBPCG with 5 eigenpairs
ADDTEST(struct_solvers.11.lobpcg 2 struct "-solver 11 -tol 1.e-6  ")
ADDTEST(struct_solvers.11.lobpcg.1 2 struct "-lobpcg -solver 11 -tol 1.e-6  -pcgitr 0 -seed 1 -vrand 1  ")
ADDTEST(struct_solvers.11.lobpcg.5 2 struct "-lobpcg -solver 11 -tol 1.e-6  -pcgitr 0 -seed 1 -vrand 5  ")

# PCG run... LOBPCG with one eigenpair .... LOBPCG with 5 eigenpairs
ADDTEST(struct_solvers.17.lobpcg 2 struct "-solver 17  ")
ADDTEST(struct_solvers.17.lobpcg.1 2 struct "-lobpcg -solver 17 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1  ")
ADDTEST(struct_solvers.17.lobpcg.5 2 struct "-lobpcg -solver 17 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 5  ")

# PCG run... LOBPCG with one eigenpair .... LOBPCG with 5 eigenpairs
ADDTEST(struct_solvers.18.lobpcg 2 struct "-solver 18  ")
ADDTEST(struct_solvers.18.lobpcg.1 2 struct "-lobpcg -solver 18 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1  ")
ADDTEST(struct_solvers.18.lobpcg.5 2 struct "-lobpcg -solver 18 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 5  ")

# PCG run... LOBPCG with one eigenpair .... LOBPCG with 5 eigenpairs
ADDTEST(struct_solvers.19.lobpcg 2 struct "-solver 19  ")
ADDTEST(struct_solvers.19.lobpcg.1 2 struct "-lobpcg -solver 19 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1  ")
ADDTEST(struct_solvers.19.lobpcg.5 2 struct "-lobpcg -solver 19 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 5  ")
#=============================================================================
# struct: Run PFMG RedBlack Gauss-Seidel tests. Nonsymmetric GS.
#=============================================================================

ADDTEST(struct_vcpfmgRedBlackGS.0 1 struct "-n 12 12 1  -d 2 -solver 1 -relax 3 -istart 1 2 0 ")

#=============================================================================
# struct: Run PFMG parallel and blocking 
#=============================================================================

ADDTEST(struct_vcpfmgRedBlackGS.1 3 struct "-n 4 12 1 -P 3 1 1 -d 2 -solver 1 -relax 3 -istart 1 2 0 ")
ADDTEST(struct_vcpfmgRedBlackGS.2 3 struct "-n 4 4 1 -P 1 3 1 -b 3 1 1 -d 2 -solver 1 -relax 3 -istart 1 2 0")

#=============================================================================
# struct: Run PFMG 2d run as 3d
#=============================================================================

ADDTEST(struct_vcpfmgRedBlackGS.3 4 struct "-n 3 1 12 -P 4 1 1 -c 1 0 1 -solver 1 -relax 3 -istart 1 0 2 ")
ADDTEST(struct_vcpfmgRedBlackGS.4 2 struct "-n 1 12 6 -P 1 1 2 -c 0 1 1 -solver 1  -relax 3 -istart 0 1 2 ")
ADDTEST(struct_vcpfmgRedBlackGS.5 3 struct "-n 12 4 1 -P 1 3 1 -c 1 1 0 -solver 1 -relax 3 -istart 1 2 0 ")


#=============================================================================
# struct: Run PFMG RedBlack Gauss-Seidel tests. Symmetric GS
#=============================================================================

ADDTEST(struct_vcpfmgRedBlackGS.6 1 struct "-n 12 12 1  -d 2 -solver 1 -relax 2 -istart 1 2 0 ")

#=============================================================================
# struct: Run PFMG parallel and blocking
#=============================================================================

ADDTEST(struct_vcpfmgRedBlackGS.7 3 struct "-n 4 12 1 -P 3 1 1 -d 2 -solver 1 -relax 2 -istart 1 2 0 ")
ADDTEST(struct_vcpfmgRedBlackGS.8 3 struct "-n 4 4 1 -P 1 3 1 -b 3 1 1 -d 2 -solver 1 -relax 2 -istart 1 2 0")

#=============================================================================
# struct: Run PFMG 2d run as 3d
#=============================================================================

ADDTEST(struct_vcpfmgRedBlackGS.9 4 struct "-n 3 1 12 -P 4 1 1 -c 1 0 1 -solver 1 -relax 2 -istart 1 0 2 ")
ADDTEST(struct_vcpfmgRedBlackGS.10 2 struct "-n 1 12 6 -P 1 1 2 -c 0 1 1 -solver 1 -relax 2 -istart 0 1 2 ")
ADDTEST(struct_vcpfmgRedBlackGS.11 3 struct "-n 12 4 1 -P 1 3 1 -c 1 1 0 -solver 1 -relax 2 -istart 1 2 0 ")

#=============================================================================
# struct: Run variable diag. PFMG RedBlack Gauss-Seidel tests. Nonsymmetric GS.
#=============================================================================

ADDTEST(struct_vdpfmgRedBlackGS.0 1 struct "-n 15 12 1  -d 2 -solver 4 -relax 3 -istart 1 2 0 ")

#=============================================================================
# struct: Run PFMG parallel and blocking 
#=============================================================================

ADDTEST(struct_vdpfmgRedBlackGS.1 3 struct "-n 5 12 1 -P 3 1 1 -d 2 -solver 4 -relax 3 -istart 1 2 0 ")
ADDTEST(struct_vdpfmgRedBlackGS.2 3 struct "-n 3 4 1 -P 1 3 1 -b 5 1 1 -d 2 -solver 4 -relax 3 -istart 1 2 0")

#=============================================================================
# struct: Run PFMG 2d run as 3d
#=============================================================================

ADDTEST(struct_vdpfmgRedBlackGS.3 5 struct "-n 3 1 12 -P 5 1 1 -c 1 0 1 -solver 4 -relax 3 -istart 1 0 2 ")
ADDTEST(struct_vdpfmgRedBlackGS.4 2 struct "-n 1 15 6 -P 1 1 2 -c 0 1 1 -solver 4  -relax 3 -istart 0 1 2 ")
ADDTEST(struct_vdpfmgRedBlackGS.5 3 struct "-n 15 4 1 -P 1 3 1 -c 1 1 0 -solver 4 -relax 3 -istart 1 2 0 ")


#=============================================================================
# struct: Run PFMG RedBlack Gauss-Seidel tests. Symmetric GS
#=============================================================================

ADDTEST(struct_vdpfmgRedBlackGS.6 1 struct "-n 15 12 1  -d 2 -solver 4 -relax 2 -istart 1 2 0 ")

#=============================================================================
# struct: Run PFMG parallel and blocking
#=============================================================================

ADDTEST(struct_vdpfmgRedBlackGS.7 3 struct "-n 5 12 1 -P 3 1 1 -d 2 -solver 4 -relax 2 -istart 1 2 0 ")
ADDTEST(struct_vdpfmgRedBlackGS.8 3 struct "-n 5 4 1 -P 1 3 1 -b 3 1 1 -d 2 -solver 4 -relax 2 -istart 1 2 0 ")

#=============================================================================
# struct: Run PFMG 2d run as 3d
#=============================================================================

ADDTEST(struct_vdpfmgRedBlackGS.9 5 struct "-n 3 1 12 -P 5 1 1 -c 1 0 1 -solver 4 -relax 2 -istart 1 0 2 ")
ADDTEST(struct_vdpfmgRedBlackGS.10 2 struct "-n 1 15 6 -P 1 1 2 -c 0 1 1 -solver 4 -relax 2 -istart 0 1 2 ")
ADDTEST(struct_vdpfmgRedBlackGS.11 3 struct "-n 15 4 1 -P 1 3 1 -c 1 1 0 -solver 4 -relax 2 -istart 1 2 0 ")

