#=============================================================================
# Run each example 
#=============================================================================
# No babel here
#ADDTEST(examples_babel.5b 4 ex5b "")
#ADDTEST(examples_babel.5b77 4 ex5b77 "")

#=============================================================================
# Run bigint examples
#=============================================================================
ADDTEST(examples_bigint.1 4 ex5big "")
ADDTEST(examples_bigint.2 8 ex15big "-n 10")

#=============================================================================
# Run complex examples
#=============================================================================
ADDTEST(examples_complex.1 16 ex18comp "-n 4")

#=============================================================================
# Run each example 
#=============================================================================
ADDTEST(examples_default.1 2 ex1 "")
ADDTEST(examples_default.2 2 ex2 "")
ADDTEST(examples_default.3 16 ex3 "-n 33 -solver 0 -v 1 1")
ADDTEST(examples_default.4 16 ex4 "-n 33 -solver 10 -K 3 -B 0 -C 1 -UO 2 -F 4")
ADDTEST(examples_default.5 4 ex5 "")
ADDTEST(examples_default.5f 4 ex5f "")
ADDTEST(examples_default.6 2 ex6 "")
ADDTEST(examples_default.7 16 ex7 "-n 33 -solver 10 -K 3 -B 0 -C 1 -UO 2 -F 4 ")
ADDTEST(examples_default.8 2 ex8 "")
ADDTEST(examples_default.9 16 ex9 "-n 33 -solver 0 -v 1 1")
ADDTEST(examples_default.10 4 ex10 "-n 120 -solver 2")
ADDTEST(examples_default.11 4 ex11 "")
ADDTEST(examples_default.12 2 ex12 "-pfmg")
ADDTEST(examples_default.12f 2 ex12f "-pfmg")
ADDTEST(examples_default.13 6 ex13 "-n 10")
ADDTEST(examples_default.14 6 ex14 "-n 10")
ADDTEST(examples_default.15 8 ex15 "-n 10")

#=============================================================================
# Run each example 
#=============================================================================
# No fortran examples available - there's code for them in the test/ folder,
# however, they are not built by any command in the native system
#ADDTEST(examples_fortran_examples.1 2 ex1_for "")
#ADDTEST(examples_fortran_examples.3 16 ex3_for "-n 33 -solver 0 -v 1 1")
#ADDTEST(examples_fortran_examples.5 4 ex5_for "")
#ADDTEST(examples_fortran_examples.6 2 ex6_for "")
#ADDTEST(examples_fortran_examples.7 16 ex7_for "-n 33 -solver 10 -K 3 -B 0 -C 1 -UO 2 -F 4")

#=============================================================================
# Run maxdim examples
#=============================================================================
ADDTEST(examples_maxdim.1 16 ex17 "-n 10")
ADDTEST(examples_maxdim.2 16 ex18 "-n 4")
