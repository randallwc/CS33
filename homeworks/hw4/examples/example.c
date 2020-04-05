#include <stdio.h>
#include <math.h>

float u2f(unsigned x) {
  return *(float*) &x;
}

int main()
{
    unsigned small = 0x00000001;// 0...01
    unsigned big = 0x7f7fffff;// 
    unsigned inf_p = 0x7f800000;// 0 111 1111 1000 0...0 //
    unsigned inf_n = 0xff800000;// 1 111 1111 1000 0...0 // 2139095040.000000
    unsigned zer_p = 0x00000000;
    unsigned zer_n = 0x80000000;
    unsigned nan_p = 0x7FFFFFFF;
    unsigned nan_n = 0xFFFFFFFF;
    printf("smallest = %f\n", u2f(small));
    printf("biggest = %f\n", u2f(big));
    printf("+00 = %f\n", u2f(inf_p)); // 4286578688.000000
    printf("-00 = %f\n", u2f(inf_n)); // 2139095040.000000
    printf("+0 = %f\n", u2f(zer_p));
    printf("-0 = %f\n", u2f(zer_n));
    printf("+nan = %f\n", u2f(nan_p));
    printf("-nan = %f\n", u2f(nan_n));
    
    return 0;
}
