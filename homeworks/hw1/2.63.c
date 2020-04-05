/*
#include <stdio.h>
#include <assert.h>
#include <limits.h>
*/

unsigned long srl(unsigned long x, int k) {
    /* Perform shift arithmetically (ex repeat msb if on a big endian machine)*/
    unsigned long xsra = (long) x >> k;

    //code//
    int w = 8 * sizeof(unsigned long); // get the number of bits in an unsigned long
    // make -1 = 111111...1111
    unsigned long mask = -1;
    // make (000...000)(111...111)
    //         k          n - k - !k
    mask = mask << (w - (!k) - k);
    // ex shift left n-k then flip it with ~
    mask = ~mask;
    // take that then and it with the xsra on the bit level
    return mask & xsra;
}

long sra(long x, int k) {
    /* Perform shift logically (ex add 0s onto the left) */
    long xsrl = (unsigned long) x >> k;

    // code //
    int w = 8 * sizeof(long);
    
    //move a 1 all the way to the begining
    long firstBit = 1 << (w - 1);
    //bitwise and it with x to find the msb
    firstBit = firstBit & x;
    //if firstBit is 0 then store all 1s
    long msb = (firstBit == 0);
    // if first bit is 1 then you want it to be all 0s
    // if first bit is 0 then you want it to be all 1s
    msb = msb - 1;
    //check if k is zero
    
    return (msb << (w - !k - k)) | xsrl;
}

/*
int main()
{
    //part a
    unsigned long a = 425;
    assert(srl(a, 5) == a >> 5);
    unsigned long b = 5;
    assert(srl(b, 1) == b >> 1);
    unsigned long c = ~0;
    assert(srl(c, 5) == c >> 5);
    unsigned long d = 5;
    assert(srl(d, 0) == d >> 0);
    unsigned long e = 0;
    int size = 8 * sizeof(unsigned long);
    assert(srl(e,size - 1) == e >> (size - 1));
    
    //part b
    long f = 425;
    assert(sra(f, 5) == f >> 5);
    long g = 5;
    assert(sra(g, 1) == g >> 1);
    long i = 5;
    assert(sra(i, 0) == i >> 0);
    long j = 0;
    int size2 = 8 * sizeof(long);
    assert(sra(j,size - 1) == j >> (size2 - 1));
    long k = -5;
    assert(sra(k, 30) == k >> (30));
    long h = ~0;
    assert(sra(h, 5) == h >> 5);
    
    return 0;
}
*/
