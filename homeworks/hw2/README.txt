First, do problem 3.61 with the following change: use the statement 'return (xp ? xp[-1] : -1);' instead of 'return (xp ? *xp : 0);'. Create a plain ASCII file named creadcmov.c containing your solution.

Second, consider the files ele.c and ele.s attached to this assignment. 'ele.c' has some constants missing, indicated by '??'. Fill them in so that a compiler ('gcc -O2 -S ele.c', say) could output assembly-language code containing a function that looks like what's in 'ele.s'. Add C-language comments to ele.c explaining (1) how to extend Equation 3.1 (page 258) to handle 3-dimensional arrays, and (2) how to derive the constants from the extended equation and from ele.s. (Or, if the constants cannot be derived exactly, explain why not.) Create a plain ASCII file ele.c containing your solution.

Also, create a plain ASCII file README containing your name and student ID, along with any other information that might be helpful to a grader.

Put your files into a directory named 'hw2' and create a tarball like this:

tar -czf hw2.tar.gz hw2/README hw2/creadcmov.c hw2/ele.c

and submit the tarball.
