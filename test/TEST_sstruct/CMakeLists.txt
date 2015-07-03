file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
    FILES_MATCHING PATTERN "*.in.*")
    
# Addtovalue
#=============================================================================
#  runs same solver for a direct setup of a matrix and an addtovalue setup
#  of the same matrix
#=============================================================================

ADDTEST(sstruct_addtovalues.0 1 sstruct "-in sstruct.in.addtoval_cellcentre -solver 11 ")
ADDTEST(sstruct_addtovalues.1 1 sstruct "-in sstruct.in.noaddtoval_cellcentre -solver 11 ")

ADDTEST(sstruct_addtovalues.2 1 sstruct "-in sstruct.in.addtoval_edges -solver 20 ")
ADDTEST(sstruct_addtovalues.3 1 sstruct "-in sstruct.in.noaddtoval_edges -solver 20 ")

ADDTEST(sstruct_addtovalues.4 2 sstruct "-in sstruct.in.addtoval_cellcentre -P 2 1 1 -solver 11 ")
ADDTEST(sstruct_addtovalues.5 2 sstruct "-in sstruct.in.noaddtoval_cellcentre -P 2 1 1 -solver 11 ")

ADDTEST(sstruct_addtovalues.6 2 sstruct "-in sstruct.in.addtoval_edges -P 2 1 1 -solver 20 ")
ADDTEST(sstruct_addtovalues.7 2 sstruct "-in sstruct.in.noaddtoval_edges -P 2 1 1 -solver 20 ")
 
# AMR2D
#=============================================================================
ADDTEST(sstruct_amr2d.0 1 sstruct "-in sstruct.in.amr.2Db -solver 18 -r 2 1 1 ")
ADDTEST(sstruct_amr2d.1 2 sstruct "-in sstruct.in.amr.2Db -solver 18 -P 2 1 1 ")
ADDTEST(sstruct_amr2d.2 1 sstruct "-in sstruct.in.amr.2Db -solver 20 -r 2 1 1 ")
ADDTEST(sstruct_amr2d.3 2 sstruct "-in sstruct.in.amr.2Db -solver 20 -P 2 1 1 ")
ADDTEST(sstruct_amr2d.4 1 sstruct "-in sstruct.in.amr.2Dc -solver 18 -r 2 1 1 ")
ADDTEST(sstruct_amr2d.5 2 sstruct "-in sstruct.in.amr.2Dc -solver 18 -P 2 1 1 ")
ADDTEST(sstruct_amr2d.6 1 sstruct "-in sstruct.in.amr.2Dc -solver 20 -r 2 1 1 ")
ADDTEST(sstruct_amr2d.7 2 sstruct "-in sstruct.in.amr.2Dc -solver 20 -P 2 1 1 ")
ADDTEST(sstruct_amr2d.8 6 sstruct "-in sstruct.in.amr.2De -solver 18 -P 6 1 1 ")

ADDTEST(sstruct_amr2d.10 1 sstruct "-in sstruct.in.amr.graphadd -solver 20 -r 2 1 1 ")
ADDTEST(sstruct_amr2d.11 2 sstruct "-in sstruct.in.amr.graphadd -solver 20 -P 2 1 1 ")

ADDTEST(sstruct_amr2d.12 1 sstruct "-in sstruct.in.amr.graphadd -solver 28 -r 1 2 1 -pooldist 0 ")
ADDTEST(sstruct_amr2d.13 4 sstruct "-in sstruct.in.amr.graphadd -solver 28 -P 1 2 1 -pooldist 1 ")
 
# Cube
 ADDTEST(sstruct_cube.0 1 sstruct "-in sstruct.in.cube -r 10 10 10 -rhsone -solver 28 ")

ADDTEST(sstruct_cube.1 1 sstruct "-in sstruct.in.bcube -r 10 10 10 -rhsone -solver 28 ")

ADDTEST(sstruct_cube.2 2 sstruct "-in sstruct.in.pcube -r 10 10 10 -rhsone -solver 28 ")
 
#=============================================================================
# sstruct: Run base 2d case
#=============================================================================

ADDTEST(sstruct_default2d.0 1 sstruct "-in sstruct.in.default_2D -r 2 2 1 -solver 19 ")

#=============================================================================
# sstruct: Run various blockings and distributions of default problem
#=============================================================================

ADDTEST(sstruct_default2d.1 1 sstruct "-in sstruct.in.default_2D -b 2 2 1 -solver 19 ")
ADDTEST(sstruct_default2d.2 2 sstruct "-in sstruct.in.default_2D -P 1 2 1 -r 2 1 1 -solver 19 ")
 
#=============================================================================
# sstruct: Run base 3d case
#=============================================================================

ADDTEST(sstruct_default3d.0 1 sstruct "-r 2 2 2 -solver 19 ")

#=============================================================================
# sstruct: Run various blockings and distributions of default problem
#=============================================================================

ADDTEST(sstruct_default3d.1 1 sstruct "-b 2 2 2 -solver 19 ")
ADDTEST(sstruct_default3d.2 2 sstruct "-P 2 1 1 -b 1 2 1 -r 1 1 2 -solver 19 ")
ADDTEST(sstruct_default3d.3 4 sstruct "-P 2 1 2 -r 1 2 1 -solver 19 ")
 
#=============================================================================
# sstruct: Run 3d problem with one proc empty. Two types of tests:
# struct solvers and sys_pfmg require the first part to be full
#              => compare runs with two refinements
# other solvers: switch the empty proc, run 1= proc 2 empty
#                                       run 2= proc 1 empty
#=============================================================================
#####
#####
ADDTEST(sstruct_emptyProc.00 2 sstruct "-in sstruct.in.emptyProc1 -r 1 1 1 -rhsone -solver 3 ")
ADDTEST(sstruct_emptyProc.01 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 10 ")
ADDTEST(sstruct_emptyProc.02 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 11 ")
ADDTEST(sstruct_emptyProc.03 2 sstruct "-in sstruct.in.emptyProc1 -r 1 1 1 -rhsone -solver 13 ")
ADDTEST(sstruct_emptyProc.04 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 18 ")
ADDTEST(sstruct_emptyProc.05 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 20 ")
ADDTEST(sstruct_emptyProc.06 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 22 ")
ADDTEST(sstruct_emptyProc.08 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 28 ")
ADDTEST(sstruct_emptyProc.09 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 30 ")
ADDTEST(sstruct_emptyProc.10 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 31 ")
ADDTEST(sstruct_emptyProc.11 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 38 ")
ADDTEST(sstruct_emptyProc.12 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 40 ")
ADDTEST(sstruct_emptyProc.14 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 42 ")
ADDTEST(sstruct_emptyProc.15 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 50 ")
ADDTEST(sstruct_emptyProc.16 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 51 ")
ADDTEST(sstruct_emptyProc.17 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 58 ")
ADDTEST(sstruct_emptyProc.18 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 60 ")
ADDTEST(sstruct_emptyProc.20 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 62 ")
ADDTEST(sstruct_emptyProc.21 2 sstruct "-in sstruct.in.emptyProc1 -rhsone -solver 120 ")
ADDTEST(sstruct_emptyProc.22 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 200 ")
ADDTEST(sstruct_emptyProc.23 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 201 ")
ADDTEST(sstruct_emptyProc.24 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 203 ")
ADDTEST(sstruct_emptyProc.25 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 210 ")
ADDTEST(sstruct_emptyProc.26 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 211 ")
ADDTEST(sstruct_emptyProc.27 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 217 ")
ADDTEST(sstruct_emptyProc.28 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 218 ")
ADDTEST(sstruct_emptyProc.29 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 220 ")
ADDTEST(sstruct_emptyProc.30 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 221 ")
ADDTEST(sstruct_emptyProc.31 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 230 ")
ADDTEST(sstruct_emptyProc.32 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 231 ")
ADDTEST(sstruct_emptyProc.33 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 237 ")
ADDTEST(sstruct_emptyProc.34 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 238 ")
ADDTEST(sstruct_emptyProc.35 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 240 ")
ADDTEST(sstruct_emptyProc.36 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 241 ")
ADDTEST(sstruct_emptyProc.37 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 247 ")
ADDTEST(sstruct_emptyProc.38 2 sstruct "-in sstruct.in.emptyProc1  -r 1 1 1 -rhsone -solver 248 ")


#=============================================================================
# run 2
#=============================================================================
ADDTEST(sstruct_emptyProc.100 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2  -rhsone -solver 3 ")
ADDTEST(sstruct_emptyProc.101 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 10 ")
ADDTEST(sstruct_emptyProc.102 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 11 ")
ADDTEST(sstruct_emptyProc.103 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 13 ")
ADDTEST(sstruct_emptyProc.104 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 18 ")
ADDTEST(sstruct_emptyProc.105 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 20 ")
ADDTEST(sstruct_emptyProc.106 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 22 ")
ADDTEST(sstruct_emptyProc.108 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 28 ")
ADDTEST(sstruct_emptyProc.109 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 30 ")
ADDTEST(sstruct_emptyProc.110 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 31 ")
ADDTEST(sstruct_emptyProc.111 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 38 ")
ADDTEST(sstruct_emptyProc.112 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 40 ")
ADDTEST(sstruct_emptyProc.114 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 42 ")
ADDTEST(sstruct_emptyProc.115 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 50 ")
ADDTEST(sstruct_emptyProc.116 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 51 ")
ADDTEST(sstruct_emptyProc.117 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 58 ")
ADDTEST(sstruct_emptyProc.118 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 60 ")
ADDTEST(sstruct_emptyProc.120 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 62 ")
ADDTEST(sstruct_emptyProc.121 2 sstruct "-in sstruct.in.emptyProc3 -rhsone -solver 120 ")
ADDTEST(sstruct_emptyProc.122 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 200 ")
ADDTEST(sstruct_emptyProc.123 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 201 ")
ADDTEST(sstruct_emptyProc.124 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 203 ")
ADDTEST(sstruct_emptyProc.125 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 210 ")
ADDTEST(sstruct_emptyProc.126 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 211 ")
ADDTEST(sstruct_emptyProc.127 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 217 ")
ADDTEST(sstruct_emptyProc.128 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 218 ")
ADDTEST(sstruct_emptyProc.129 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 220 ")
ADDTEST(sstruct_emptyProc.130 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 221 ")
ADDTEST(sstruct_emptyProc.131 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 230 ")
ADDTEST(sstruct_emptyProc.132 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 231 ")
ADDTEST(sstruct_emptyProc.133 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 237 ")
ADDTEST(sstruct_emptyProc.134 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 238 ")
ADDTEST(sstruct_emptyProc.135 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 240 ")
ADDTEST(sstruct_emptyProc.136 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 241 ")
ADDTEST(sstruct_emptyProc.137 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 247 ")
ADDTEST(sstruct_emptyProc.138 2 sstruct "-in sstruct.in.emptyProc2 -r 2 2 2 -rhsone -solver 248 ")
 
 #=============================================================================
# no test comparison at this time
#=============================================================================

ADDTEST(maxwell_maxwell.0 1 maxwell_unscaled "-in sstruct.in.maxwell3d_unscaled -solver 1 ")
ADDTEST(maxwell_maxwell.1 2 maxwell_unscaled "-in sstruct.in.maxwell3d_unscaled -solver 1 -P 2 1 1 ")
ADDTEST(maxwell_maxwell.2 2 maxwell_unscaled "-in sstruct.in.maxwell3d_unscaled -solver 1 -P 2 1 1 -r 2 3 1 ")
 
#=============================================================================
# sstruct: Run all of the solvers
#=============================================================================
ADDTEST(sstruct_miller.0 2 sstruct "-in sstruct.in.miller_2blk  -r 5 10 1 -P 2 1 1 -solver 11 ")
ADDTEST(sstruct_miller.1 2 sstruct "-in sstruct.in.miller_2blk  -r 5 10 1 -P 2 1 1 -solver 20 ")
ADDTEST(sstruct_miller.2 2 sstruct "-in sstruct.in.miller_2blk1 -r 5 10 1 -P 2 1 1 -solver 11 ")
ADDTEST(sstruct_miller.3 2 sstruct "-in sstruct.in.miller_2blk1 -r 5 10 1 -P 2 1 1 -solver 20 ")
ADDTEST(sstruct_miller.4 2 sstruct "-in sstruct.in.miller_2stk  -r 5 10 1 -P 2 1 1 -solver 11 ")
ADDTEST(sstruct_miller.5 2 sstruct "-in sstruct.in.miller_2stk  -r 5 10 1 -P 2 1 1 -solver 20 ")
ADDTEST(sstruct_miller.6 2 sstruct "-in sstruct.in.miller_3blk  -r 5 10 1 -P 2 1 1 -solver 11 ")
ADDTEST(sstruct_miller.7 2 sstruct "-in sstruct.in.miller_3blk  -r 5 10 1 -P 2 1 1 -solver 20 ")
ADDTEST(sstruct_miller.8 2 sstruct "-in sstruct.in.miller_diag  -r 10 20 1 -P 2 1 1 -solver 11 ")
ADDTEST(sstruct_miller.9 2 sstruct "-in sstruct.in.miller_diag  -r 10 20 1 -P 2 1 1 -solver 20 ")
 
# Neighborpart
#=============================================================================
 ADDTEST(sstruct_neighborpart.0 1 sstruct "-in sstruct.in.fe_node1_2D -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.1 2 sstruct "-in sstruct.in.fe_node2_2D -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.2 2 sstruct "-in sstruct.in.fe_node2_2D_coord -solver 8 -rhsone ")
ADDTEST(struct_neighborpart.3 1 struct "-n 5 5 1 -d 2 -solver 8 ")

ADDTEST(sstruct_neighborpart.10 2 sstruct "-in sstruct.in.fe_all2_2D -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.11 2 sstruct "-in sstruct.in.fe_all2_2D_coord -solver 8 -rhsone ")

ADDTEST(sstruct_neighborpart.20 2 sstruct "-in sstruct.in.fe_all2_3D -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.21 2 sstruct "-in sstruct.in.fe_all2_3D_coord -solver 8 -rhsone ")

ADDTEST(sstruct_neighborpart.30 2 sstruct "-in sstruct.in.fe_all2_2D -r 2 1 1 -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.31 2 sstruct "-in sstruct.in.fe_all2_2D -b 2 1 1 -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.32 4 sstruct "-in sstruct.in.fe_all2_2D -P 2 1 1 -solver 8 -rhsone ")

ADDTEST(sstruct_neighborpart.40 1 sstruct "-in sstruct.in.fe_all3_3D -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.41 1 sstruct "-in sstruct.in.fe_all3_3D_coord -solver 8 -rhsone ")

ADDTEST(sstruct_neighborpart.50 1 sstruct "-in sstruct.in.fe_all3_3D -r 1 1 2 -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.51 1 sstruct "-in sstruct.in.fe_all3_3D -b 1 1 2 -solver 8 -rhsone ")
ADDTEST(sstruct_neighborpart.52 2 sstruct "-in sstruct.in.fe_all3_3D -P 1 1 2 -solver 8 -rhsone ")

ADDTEST(sstruct_neighborpart.60 2 sstruct "-in sstruct.in.fe_all2_2D -solver 28 -rhsone ")
ADDTEST(sstruct_neighborpart.61 2 sstruct "-in sstruct.in.fe_all2_2Ds -solver 28 -rhsone ")
ADDTEST(sstruct_neighborpart.62 2 sstruct "-in sstruct.in.fe_all2_2Dss -solver 28 -rhsone ")
 
#=============================================================================
# sstruct: Run base 3d cases
#=============================================================================

ADDTEST(sstruct_neumann.0 1 sstruct "-in sstruct.in.neumann -r 6 6 6 -solver 200 ")
ADDTEST(sstruct_neumann.1 1 sstruct "-in sstruct.in.neumann -r 6 6 6 -solver 201 ")

#=============================================================================
# sstruct: Run various blockings and distributions
#=============================================================================

ADDTEST(sstruct_neumann.2 4 sstruct "-in sstruct.in.neumann -P 2 2 1 -b 1 3 2 -r 3 1 3 -solver 200 ")
ADDTEST(sstruct_neumann.3  3 sstruct "-in sstruct.in.neumann -P 1 1 3 -b 6 1 1 -r 1 6 2 -solver 201 ")
 
#=============================================================================
# Check SetNeighborBox for periodic problems (2D)
#=============================================================================

ADDTEST(sstruct_periodic.20 1 sstruct "-in sstruct.in.periodic.2D -r 20 20 1-solver 11 ")
ADDTEST(sstruct_periodic.21 2 sstruct "-in sstruct.in.periodic.2D -r 20 10 1 -P 1 2 1-solver 11 ")

#=============================================================================
# Check SetNeighborBox for periodic problems (3D)
#=============================================================================

ADDTEST(sstruct_periodic.30 1 sstruct "-in sstruct.in.periodic -r 20 20 20-solver 11 ")
ADDTEST(sstruct_periodic.31 2 sstruct "-in sstruct.in.periodic -r 20 20 10 -P 1 1 2-solver 11 ")

#=============================================================================
# Check SysPFMG for power-of-two and non-power-of-two systems
#=============================================================================

# power-of-two
ADDTEST(sstruct_periodic.40 1 sstruct "-in sstruct.in.laps.periodic -r 16 16 1 -P 1 1 1 -solver 3")
ADDTEST(sstruct_periodic.41 2 sstruct "-in sstruct.in.laps.periodic -r  8 16 1 -P 2 1 1 -solver 3")
ADDTEST(sstruct_periodic.42 2 sstruct "-in sstruct.in.laps.periodic -r 16  8 1 -P 1 2 1 -solver 3")

# non-power-of-two
ADDTEST(sstruct_periodic.50 1 sstruct "-in sstruct.in.laps.periodic -r 22 22 1 -P 1 1 1 -solver 3")
ADDTEST(sstruct_periodic.51 2 sstruct "-in sstruct.in.laps.periodic -r 11 22 1 -P 2 1 1 -solver 3")
ADDTEST(sstruct_periodic.52 2 sstruct "-in sstruct.in.laps.periodic -r 22 11 1 -P 1 2 1 -solver 3")

#=============================================================================
# Check PFMG, SMG, and SysPFMG for problems with period larger than the grid
#=============================================================================

# First check that sstruct and struct are the same here
ADDTEST(sstruct_periodic.60 2 struct "-d 2 -n 8 16 1 -P 2 1 1 -p 16 0 0 -istart 0 0 0-solver 0 ")
ADDTEST(sstruct_periodic.61 2 sstruct "-in sstruct.in.periodic.bigA -r 1 2 1 -P 2 1 1 -rhsone-solver 200 ")
ADDTEST(sstruct_periodic.62 2 struct "-d 2 -n 8 16 1 -P 2 1 1 -p 16 0 0 -istart 0 0 0-solver 1 ")
ADDTEST(sstruct_periodic.63 2 sstruct "-in sstruct.in.periodic.bigA -r 1 2 1 -P 2 1 1 -rhsone-solver 201 ")

ADDTEST(sstruct_periodic.65 2 sstruct "-in sstruct.in.periodic.bigB -r 3 6 1 -P 2 1 1 -rhsone-solver 200 ")
ADDTEST(sstruct_periodic.66 2 sstruct "-in sstruct.in.periodic.bigB -r 3 6 1 -P 2 1 1 -rhsone-solver 201 ")
ADDTEST(sstruct_periodic.67 2 sstruct "-in sstruct.in.periodic.bigB -r 3 6 1 -P 2 1 1 -rhsone-solver 3 ")

#=============================================================================
# Check that reverse communication used to AddValues still works
#=============================================================================

ADDTEST(sstruct_periodic.70 2 sstruct "-in sstruct.in.periodic.add -solver 218 -P 1 1 2")

#=============================================================================
# Check SetPeriodic for node/cell problems and STRUCT, SSTRUCT, PARCSR types
#=============================================================================
ADDTEST(sstruct_periodic.80 6 sstruct "-in sstruct.in.periodic.cellA -P 1 6 1 -solver 218 -rhsone")
ADDTEST(sstruct_periodic.81 6 sstruct "-in sstruct.in.periodic.cellA -P 1 6 1 -solver  18 -rhsone")
ADDTEST(sstruct_periodic.82 6 sstruct "-in sstruct.in.periodic.cellA -P 1 6 1 -solver  28 -rhsone")
ADDTEST(sstruct_periodic.83 6 sstruct "-in sstruct.in.periodic.cellB -P 1 6 1 -solver 218 -rhsone")
ADDTEST(sstruct_periodic.84 6 sstruct "-in sstruct.in.periodic.cellB -P 1 6 1 -solver  18 -rhsone")
ADDTEST(sstruct_periodic.85 6 sstruct "-in sstruct.in.periodic.cellB -P 1 6 1 -solver  28 -rhsone")

ADDTEST(sstruct_periodic.90 6 sstruct "-in sstruct.in.periodic.nodeA -P 1 6 1 -solver 218 -rhsone")
ADDTEST(sstruct_periodic.91 6 sstruct "-in sstruct.in.periodic.nodeA -P 1 6 1 -solver  18 -rhsone")
ADDTEST(sstruct_periodic.92 6 sstruct "-in sstruct.in.periodic.nodeA -P 1 6 1 -solver  28 -rhsone")
ADDTEST(sstruct_periodic.93 6 sstruct "-in sstruct.in.periodic.nodeB -P 1 6 1 -solver 218 -rhsone")
ADDTEST(sstruct_periodic.94 6 sstruct "-in sstruct.in.periodic.nodeB -P 1 6 1 -solver  18 -rhsone")
ADDTEST(sstruct_periodic.95 6 sstruct "-in sstruct.in.periodic.nodeB -P 1 6 1 -solver  28 -rhsone")

# Sharedpart
#=============================================================================
# These produce the same rel residual
ADDTEST(sstruct_sharedpart.0 1 sstruct "-in sstruct.in.reduced3D -solver 28 ")
ADDTEST(sstruct_sharedpart.1 3 sstruct "-in sstruct.in.reduced3D -solver 28 -pooldist 1 ")
ADDTEST(sstruct_sharedpart.2 1 sstruct "-in sstruct.in.reduced3D-4 -solver 28 ")
ADDTEST(sstruct_sharedpart.3 3 sstruct "-in sstruct.in.reduced3D-4 -solver 28 -pooldist 1 ")

# These produce the same rel residual
ADDTEST(sstruct_sharedpart.10 1 sstruct "-in sstruct.in.enhanced3D -solver 28 ")
ADDTEST(sstruct_sharedpart.11 7 sstruct "-in sstruct.in.enhanced3D -solver 28 -pooldist 1 ")

# Check AMG
ADDTEST(sstruct_sharedpart.50 3 sstruct "-in sstruct.in.reduced3D -solver 20 -pooldist 1 ")
ADDTEST(sstruct_sharedpart.51 7 sstruct "-in sstruct.in.enhanced3D -solver 20 -pooldist 1 ")
ADDTEST(sstruct_sharedpart.52 3 sstruct "-in sstruct.in.reduced3D-4 -solver 20 -pooldist 1 ")
ADDTEST(sstruct_sharedpart.53 5 sstruct "-in sstruct.in.fe_rhombus5 -solver 20 ")
 
#=============================================================================
# sstruct: Run all of the solvers
#=============================================================================

ADDTEST(sstruct_solvers.0 2 sstruct "-P 1 1 2 -solver 10 ")
ADDTEST(sstruct_solvers.1 2 sstruct "-P 1 1 2 -solver 11 ")
ADDTEST(sstruct_solvers.2 2 sstruct "-P 1 1 2 -solver 18 ")
ADDTEST(sstruct_solvers.3 2 sstruct "-P 1 1 2 -solver 19 ")
ADDTEST(sstruct_solvers.4 2 sstruct "-P 1 1 2 -solver 20 ")
ADDTEST(sstruct_solvers.5 2 sstruct "-P 1 1 2 -solver 21 ")
ADDTEST(sstruct_solvers.6 2 sstruct "-P 1 1 2 -solver 22 ")
ADDTEST(sstruct_solvers.7 2 sstruct "-P 1 1 2 -solver 30 ")
ADDTEST(sstruct_solvers.8 2 sstruct "-P 1 1 2 -solver 31 ")
ADDTEST(sstruct_solvers.9 2 sstruct "-P 1 1 2 -solver 38 ")
ADDTEST(sstruct_solvers.10 2 sstruct "-P 1 1 2 -solver 39 ")
ADDTEST(sstruct_solvers.11 2 sstruct "-P 1 1 2 -solver 40 ")
ADDTEST(sstruct_solvers.12 2 sstruct "-P 1 1 2 -solver 41 ")
ADDTEST(sstruct_solvers.13 2 sstruct "-P 1 1 2 -solver 42 ")
ADDTEST(sstruct_solvers.14 2 sstruct "-in sstruct.in.laps -P 2 1 1 -solver 3 ")
ADDTEST(sstruct_solvers.15 1 sstruct "-in sstruct.in.marinak -P 1 1 1 -solver 20 ")
ADDTEST(sstruct_solvers.16 2 sstruct "-P 1 1 2 -solver 70 ")
ADDTEST(sstruct_solvers.17 2 sstruct "-P 1 1 2 -solver 71 ")
ADDTEST(sstruct_solvers.18 2 sstruct "-P 1 1 2 -solver 78 ")
ADDTEST(sstruct_solvers.19 2 sstruct "-P 1 1 2 -solver 80 ")
ADDTEST(sstruct_solvers.20 2 sstruct "-P 1 1 2 -solver 90 ")

#=============================================================================
# Run default case with all available PCG preconditioners (solvers): 
#    10: SMG
#    11: PFMG
#    18: Diagonal scaling
#    19: none
#=============================================================================

# PCG run... LOBPCG run for one eigenpair ... LOBPCG run for 4 eigenpairs
ADDTEST(sstruct_solvers.10.lobpcg 2 sstruct "-P 1 1 2 -solver 10 -tol 1.e-6 ")
ADDTEST(sstruct_solvers.10.lobpcg.1 2 sstruct "-P 1 1 2 -lobpcg -solver 10 -tol 1.e-6 -pcgitr 0 -seed 1 -vrand 1 ")
ADDTEST(sstruct_solvers.10.lobpcg.4 2 sstruct "-P 1 1 2 -lobpcg -solver 10 -tol 1.e-6 -pcgitr 0  -seed 1 -vrand 4  ")

# PCG run... LOBPCG run for one eigenpair ... LOBPCG run for 4 eigenpairs
ADDTEST(sstruct_solvers.11.lobpcg 2 sstruct "-P 1 1 2 -solver 11 -tol 1.e-6  ")
ADDTEST(sstruct_solvers.11.lobpcg.1 2 sstruct "-P 1 1 2 -lobpcg -solver 11 -tol 1.e-6  -pcgitr 0 -seed 1 -vrand 1  ")
ADDTEST(sstruct_solvers.11.lobpcg.4 2 sstruct "-P 1 1 2 -lobpcg -solver 11 -tol 1.e-6  -pcgitr 0 -seed 1 -vrand 4  ")

# PCG run... LOBPCG run for one eigenpair ... LOBPCG run for 4 eigenpairs
ADDTEST(sstruct_solvers.18.lobpcg 2 sstruct "-P 1 1 2 -solver 18  ")
ADDTEST(sstruct_solvers.18.lobpcg.1 2 sstruct "-P 1 1 2 -lobpcg -solver 18 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1  ")
ADDTEST(sstruct_solvers.18.lobpcg.4 2 sstruct "-P 1 1 2 -lobpcg -solver 18 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 4  ")

# PCG run... LOBPCG run for one eigenpair ... LOBPCG run for 4 eigenpairs
ADDTEST(sstruct_solvers.19.lobpcg 2 sstruct "-P 1 1 2 -solver 19  ")
ADDTEST(sstruct_solvers.19.lobpcg.1 2 sstruct "-P 1 1 2 -lobpcg -solver 19 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 1  ")
ADDTEST(sstruct_solvers.19.lobpcg.4 2 sstruct "-P 1 1 2 -lobpcg -solver 19 -tol 1.e-6  -pcgitr 10 -seed 1 -vrand 4  ")

# SSTRUCT_STRUCT
#=============================================================================
# Compare the struct solvers called from sstruct & struct interfaces
#=============================================================================

ADDTEST(sstruct_struct.1 1 struct "-n 12 12 12 -solver 1 -istart -3 -3 -3 -relax 1 -rap 1")
ADDTEST(sstruct_struct.201 1 sstruct "-in sstruct.in.struct -solver 201 -relax 1 -rap 1 -rhsone")

ADDTEST(sstruct_struct.0 1 struct "-n 12 12 12 -solver 0 -istart -3 -3 -3 -relax 1")
ADDTEST(sstruct_struct.200 1 sstruct "-in sstruct.in.struct -solver 200 -relax 1 -rhsone")

#=============================================================================
# Compare 19pt, 7pt, positive, and negative definite
#=============================================================================

ADDTEST(sstruct_struct.10 2 sstruct "-in sstruct.in.19aniso  -P 2 1 1 -solver 201")
ADDTEST(sstruct_struct.11 2 sstruct "-in sstruct.in.p19aniso -P 2 1 1 -solver 201")
ADDTEST(sstruct_struct.12 2 sstruct "-in sstruct.in.7aniso   -P 2 1 1 -solver 201")
ADDTEST(sstruct_struct.13 2 sstruct "-in sstruct.in.p7aniso  -P 2 1 1 -solver 201")

ADDTEST(sstruct_struct.15 2 sstruct "-in sstruct.in.19iso  -P 2 1 1 -solver 201")
ADDTEST(sstruct_struct.16 2 sstruct "-in sstruct.in.p19iso -P 2 1 1 -solver 201")
ADDTEST(sstruct_struct.17 2 sstruct "-in sstruct.in.7iso   -P 2 1 1 -solver 201")
ADDTEST(sstruct_struct.18 2 sstruct "-in sstruct.in.p7iso  -P 2 1 1 -solver 201")

#=============================================================================
# sstruct: Check SetSymmetric for HYPRE_SSTRUCT data type (2D)
#=============================================================================

ADDTEST(sstruct_symm.20 1 sstruct "-in sstruct.in.symm0.2D -r 10 10 10 -solver 18")
ADDTEST(sstruct_symm.21 1 sstruct "-in sstruct.in.symm1.2D -r 10 10 10 -solver 18")
ADDTEST(sstruct_symm.22 1 sstruct "-in sstruct.in.symm2.2D -r 10 10 10 -solver 18")
ADDTEST(sstruct_symm.23 1 sstruct "-in sstruct.in.symm3.2D -r 10 10 10 -solver 18")

#=============================================================================
# sstruct: Check SetSymmetric for HYPRE_PARCSR data type (2D)
#=============================================================================

ADDTEST(sstruct_symm.24 1 sstruct "-in sstruct.in.symm0.2D -r 10 10 10 -solver 28")
ADDTEST(sstruct_symm.25 1 sstruct "-in sstruct.in.symm1.2D -r 10 10 10 -solver 28")

#=============================================================================
# sstruct: Check SetSymmetric for HYPRE_SSTRUCT data type (3D)
#=============================================================================

ADDTEST(sstruct_symm.30 1 sstruct "-in sstruct.in.symm0 -r 10 10 10 -solver 18")
ADDTEST(sstruct_symm.31 1 sstruct "-in sstruct.in.symm1 -r 10 10 10 -solver 18")
ADDTEST(sstruct_symm.32 1 sstruct "-in sstruct.in.symm2 -r 10 10 10 -solver 18")
ADDTEST(sstruct_symm.33 1 sstruct "-in sstruct.in.symm3 -r 10 10 10 -solver 18")

#=============================================================================
# sstruct: Check SetSymmetric for HYPRE_PARCSR data type (3D)
#=============================================================================

ADDTEST(sstruct_symm.34 1 sstruct "-in sstruct.in.symm0 -r 10 10 10 -solver 28")
ADDTEST(sstruct_symm.35 1 sstruct "-in sstruct.in.symm1 -r 10 10 10 -solver 28")

# ZCube
#=============================================================================
ADDTEST(sstruct_zcube.0 1 sstruct "-in zsstruct.in.cube -r 10 10 10 -rhsone -solver 28")
ADDTEST(sstruct_zcube.1 1 sstruct "-in zsstruct.in.bcube -r 10 10 10 -rhsone -solver 28")