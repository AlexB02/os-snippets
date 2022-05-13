/* Test and Set Lock */

/* TSL(LOCK) is an atomic functions to set the memory location LOCK to 1, 
  and return its previous value */

// TSL() = 0 gives that CR is vacant, you may obtain it
// TSL() = 1 gives that CR is occupied, please wait

int TSL(int *L);

// A spin lock as we test repeatedly, causing a spin
void lock(int *L)
{
  while (TSL(L) != 0) /* busily wait */;
}
