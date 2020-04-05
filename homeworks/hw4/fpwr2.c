#include <stdio.h>
#include <assert.h>
#include <math.h>

static float u2f(unsigned u) {
  //unsigned to float
  float *ptr = &u;//ptr to float and set it equal to the unsigned val
  return *ptr;//return dereferenced
}

float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

	if (x < 1 - (pow(2,7) - 1) - 23) {// lowest exponent is 1 - bias - 23 = -149
	/* Too small. Return 0.0 */
	exp = 0;
	frac = 0;
	} else if(x< 1 - (pow(2,7) - 1) ){// denormalized is anything above 1 - bias = -126
	/* Denormalized result */ 
	exp = 0;
	frac = 1 << (unsigned)(x + 149);// x - (1 - bias - 23)
	} else if (x < (pow(2,7)-1) + 1) {// normalized is bias + 1 = 128
	/* Normalized result. */
	exp = x + 127;// x + bias = x + (2^7) - 1
	frac = 0;
	} else {
	/* Too big. Return +oo */
	exp = 0xFF;// infinity is an exponent value of all 1's
	frac = 0;
	}

	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	/* Return as float */
	return u2f(u);
}

/*
int main() {
  printf("start\n");
  assert(fpwr2(0) == powf(2,0));
  assert(fpwr2(99) == powf(2,99));
  assert(fpwr2(-99) == powf(2,-99));
  assert(fpwr2(12000) == powf(2,12000));
  assert(fpwr2(-10900) == powf(2,-10900));
  printf("done\n");
  return 0;
}
*/
