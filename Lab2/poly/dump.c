//
// dump.c
//
#include <stdio.h>

void dump_memory(void *p, int len)
{
  int i;
  printf("|%-14s|%s|%s|%-6s|%-11s|%-13s|%-13s|\n","address","char","hexCh","short","integer","float","doubleFloat");
  for (i = 0; i < len; i++) {
    printf("%8p %c 0x%02x %+hd %+d %+g %+lg\n", p + i, *(unsigned char *)(p + i), *(unsigned char *)(p + i), *(unsigned short *)(p + i), *(unsigned int *)(p + i), *(float *)(p + i), *(double *)(p + i));
  }
}
