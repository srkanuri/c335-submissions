#include <stdio.h>

int main(){
  char a[100];
  int i;
  while(scanf("%s",a)){
    printf("Value entered is %s\n", a);
    if(isdigit(a)){
      int val = strtol(a,&a,10);
      printf("%d",val);
    }
    for(i=0;a[i]!='\0';i++){
      printf("%c\n",a[i]);
    }
  }
}

/*int main(){
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
  }*/
