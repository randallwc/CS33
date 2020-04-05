First, problem 2.90 in the textbook. Submit a source-code file named 'fpwr2.c' that contains all the source code for fpwr2, preceded by the definition of a function 'static float u2f(unsigned u) { ... }' that returns a value as described in 2.90 (you fill in the "...").

Second, consider the file fmatest.c, a program that uses the standard C function fmaf. Copy it to lnxsrv10.seas.ucla.edu (the '10' is important!) and compile it as follows:

gcc -O2 -S -march=native -ffp-contract=off fmatest.c

In this file f1 and f2 have identical source code, except that where f1 has 'fmaf (a, b, c)', f2 has 'a * b + c'. And the documentation for 'fmaf (a, b, c)' says that it returns (a * b + c). And yet f1 and f2 have different machine code. Explain what the machine instructions in f1 and f2 do, and why GCC generated these differing sets of instructions. (You need not explain the machine instructions in the fmatest function.) Assuming the default rounding mode of round-to-nearest, give three finite floating-point constants a, b and c such that 'fmatest (a, b, c)' returns true, and explain why it returns true for these three arguments. Submit an ASCII text file 'fmatest.txt' containing your explanations.
