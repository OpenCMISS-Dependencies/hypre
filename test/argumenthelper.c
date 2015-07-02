#include <stdio.h>

int main(int argc, char* argv[], char* env[])
{
  int i;
  for(i = 0; i < argc; ++i)
    fprintf(stderr, "arg[%d] = %s\n", i, argv[i]);
#if 0
  for (i=0; env[i]; ++i)
    fprintf(stderr,"env[%d] = %s\n", i, env[i]);
#endif

  return -1;
}
