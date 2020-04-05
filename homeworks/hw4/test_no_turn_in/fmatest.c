#include <math.h>

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

