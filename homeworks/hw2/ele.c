#define R 3
#define S 19
#define T 2

int A[R][S][T];

int
ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}

/*
 * part (1)
 * Add C-language comments to ele.c explaining (1) how to 
 * extend Equation 3.1 (page 258) to handle 3-dimensional arrays
 *
 * Equation 3.1 is &D[i][j] = D + L(C * i + j)
 * for 2d arrays the formula for an array of T type and size L
 * with declaration T D[R][C].
 *
 * To extend this we can think of a 3d array A[R][S][T]
 * with made of a type with size L also.
 * First, we start at the position of the start of the 3d array
 * which is denoted by A and we will then traverse the rest of the array
 * by adding L - the size of each element - times the indexing of the rows,
 * columns, and height.  In the 2d example we can see that we must traverse a whole
 * column to traverse one row.  In this 3d example we must traverse a whole S * T
 * to traverse one R because of the added dimension.  This means that to also move one in S
 * we must traverse an entire T and finally we can step through the T's.
 * This yields an equation that is
 * &A[i][j][k] = A + L(S * T * i + T * j + k)
 * original_position + size_of_element_of_A * (column * height * r_index + height * s_index + t_index)
*/

/*
 * part (2)
 * how to derive the constants from the extended equation and from ele.s
 *
i in %rdi
j in %rsi
k in %rdx

movl    $3, %eax                ->      %eax and %rax are 3
subq    %rdi, %rax              ->      %rax - %rdi                     ->      3 - i is %rax
leaq    (%rax,%rax,8), %rcx     ->      9 * %rax                        ->      9 * (3 - i) is %rcx
leaq    (%rax,%rcx,2), %rax     ->      (3 - i) + 2 * (9 * (3 - i))     ->      19 * (3 - i) is %rax
subq    %rsi, %rax              ->      19 * (3 - i) - j is %rax
leaq    1(%rdx,%rax,2), %rax    ->      1 + k + (2 * (19 * (3 - i) - j))->      1 + k + 38 * (3 - i) - (2 * j) is %rax
movl    A(,%rax,4), %eax        ->      A + 4 * (1 + k + (2 * (19 * (3 - i) - j))) is returned  
ret                             ->      A + 4 * (2*19*(R-i) - 2 * j + k + 1)
 *
 * We can see from the final equation of A + 4 * (2*19*(R-i) - 2 * j + k + 1)
 * that it is fairly similar to the equation we derived which was
 * A + L(S * T * i + T * j + k)
 * We can see that the A is the same as the starting position of the array.
 * We can also see that L- size of each element- is 4 in this format of an int array.
 * We can also see that from the function ele the first index is R-i
 * we can see that in our final equation 3-i is multiplied by two numbers 
 * much like the equation we made where i is multiplied by S and T.
 * We can use this and find R to be 3 because the formula we made was
 * for the form A[i][j][k] but this function is A[R - i][1 - j][k - 1].
 * We can also see that there are two numbers multiplying onto the first index - (3-i)
 * and there is one number multiplying by j - (the second index). 19 and 2 multiply 
 * against the first index and only 2 multiplies by the second index of j.  This is a
 * similarity between this formula and the one we created because T multiplies against
 * i and j.  This means T must be 2 and 19 must be S because S in our initial equation
 * is only multiplied against the first index and not the second.  J in our final equation
 * that we derived is negative because of the inintial conditions we recieved from the function
 * where the second index is (1-j) and not j (the way our predefined function was formated).
 * R == 3
 * S == 19
 * T == 2
*/
