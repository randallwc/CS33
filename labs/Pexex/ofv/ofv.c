_Bool
testovf (long n)
{
  return n + 9223372036854775807 < n;
}
