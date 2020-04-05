#include <math.h>
#include <stdio.h>
#include <assert.h>

float
f1 (float a, float b, float c)
{
  return fmaf (a, b, c);
}

float
f2 (float a, float b, float c)
{
  return a * b + c;
}

_Bool
fmatest (float a, float b, float c)
{
  return f1 (a, b, c) != f2 (a, b, c);
}

int main(){
  printf("start\n");

  float a = 3.4028235e38;
  float b = 2;
  float c = -3.4028235e38;
  
/*
 *    float a = 4;
 *    float b = 5;
 *    float c = 6;
*/

  printf("%f\n",f1(a,b,c));
  printf("%f\n",f2(a,b,c));

  assert(!(fmatest (a,b,c)));

  printf("done\nthey are equal\n");
  return 0;
}

