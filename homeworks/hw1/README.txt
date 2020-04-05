Do homework problems 2.63, 2.72, 2.73, and 2.82 from Bryant & O'Hallaron 3rd edition, with the following changes and additions:

In problem 2.63, the types of the functions' first arguments and returned values should be long and unsigned long, not int and unsigned. (The type of the second arguments remains int.) Also, check your 2.63 solution with both 'gcc -m32' and 'gcc -m64'.
Redo problem 2.73, this time using a call to the __builtin_add_overflow_p function available in GCC 7 and later; the third argument of the call should be a cast that consists of a parenthesized type followed by the constant 0. In other respects your function should continue to follow the bit-level integer coding rules.
In problem 2.82, also analyze the following expressions:
F.
x % 8 == (x & 7)
G.
((unsigned) -1 / 255 * (x & 255)) >> 24 == (x & 255)
Submit your homework answers as a gzipped tarball containing your answers to each problem, in the files hw1/2.63.c, hw1/2.72.txt, hw1/2.73.c, hw1/2.73-redo.txt, and hw1/2.82.c respectively. The .txt files should be plain ASCII text files with lines terminated by LF. The .c files should compile cleanly with shell commands like this:

gcc -m32 -fwrapv -O2 -Wall -Wextra -S hw1/2.73.c
As we will grade your submission with the latest version of GCC installed in /usr/local/cs/bin/ on the newer SEASnet GNU/Linux servers (lnxsrv06, lnxsrv07, lnxsrv09 and lnxsrv10), using the flags shown above, it would be wise to check your work on that platform. The shell command 'which gcc' should output '/usr/local/cs/bin/gcc'.

To create your tarball, use the shell command:

tar -czf hw1.tar.gz hw1/2.63.c hw1/2.72.txt hw1/2.73.c hw1/2.82.txt hw1/2.73-redo.c
