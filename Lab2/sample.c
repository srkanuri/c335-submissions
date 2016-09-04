#include <stdio.h>

int main(){
  printf("%d\n",65535.2345);
  printf("%0hd\n", 65535.2345);
  printf("%ld\n", 65535.2345);
  printf("%0x\n", 65535.2345);
  printf("%c\n", 65535.2345);
  printf("%s\n", 65535.2345);
  printf("%p\n", 65535.2345);
  printf("%-f\n", 65535.2345);
  printf("%+e\n", 65535.2345);
  printf("%10d\n", 65535.2345);
  printf("%08x\n", 65535.2345);
  printf("%10u\n", 65535.2345);
  printf("%10c\n", 65535.2345);
  printf("%10s\n", 65535.2345);
  printf("%10.2f\n", 65535.2345);
  printf("%10eg\n", 65535.2345);
}
