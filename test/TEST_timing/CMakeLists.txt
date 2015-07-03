#=============================================================================
# struct: timing and parallel scaling efficiency test
#=============================================================================

#=============================================================================
# Perform as a single psub process, throw away the first test in
# each configuration
#=============================================================================
ADDTEST(struct_efficiency.0a 1 struct "-n 30 30 30 -solver 11 ")
ADDTEST(struct_efficiency.0 1 struct "-n 30 30 30 -solver 11 ")
ADDTEST(struct_efficiency.1 1 struct "-n 30 30 30 -solver 11 ")
ADDTEST(struct_efficiency.2 1 struct "-n 30 30 30 -solver 11 ")

ADDTEST(struct_efficiency.3a 8 struct "-n 30 30 30 -P 2 2 2 -solver 11 ")
ADDTEST(struct_efficiency.3 8 struct "-n 30 30 30 -P 2 2 2 -solver 11 ")
ADDTEST(struct_efficiency.4 8 struct "-n 30 30 30 -P 2 2 2 -solver 11 ")
ADDTEST(struct_efficiency.5 8 struct "-n 30 30 30 -P 2 2 2 -solver 11 ")

ADDTEST(struct_efficiency.6a 64 struct "-n 30 30 30 -P 4 4 4 -solver 11 ")
ADDTEST(struct_efficiency.6 64 struct "-n 30 30 30 -P 4 4 4 -solver 11 ")
ADDTEST(struct_efficiency.7 64 struct "-n 30 30 30 -P 4 4 4 -solver 11 ")
ADDTEST(struct_efficiency.8 64 struct "-n 30 30 30 -P 4 4 4 -solver 11 ")
