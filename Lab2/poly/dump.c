//
// dump.c
//
#include <stdio.h>

void dump_memory(void *p, int len)
{
  int i;
  printf("%-14s  %4s %5s %-6s %+11s%+13s %+13s\n","address","char","hexCh","short","integer","float","doubleFloat");
  for (i = 0; i < len; i++) {
    char tmp = *(unsigned char *)(p + i);
    printf("%+14p %4c 0x%02x %+6hd %+11d %+13e %+13e\n", p + i, ((tmp>31 && tmp<128) ? tmp :'?'), *(unsigned char *)(p + i), *(unsigned short *)(p + i), *(unsigned int *)(p + i), *(float *)(p + i), *(double *)(p + i));
  }
}
