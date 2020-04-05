/*
long cread(long *xp) {
  return(xp ? *xp : 0);
}
*/

long v = -1;//store outside so we can reference it as a pointer
long creadi_alt(long *xp){
  return *(xp ? xp - sizeof(long):&(v));//compare all as pointers then dereference the returned value
}

/*
 * want it to do a conditional data transfer
 * want it to generate code with a conditional move 
 * rather than a jump instruction
*/

