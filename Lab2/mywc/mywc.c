#include <stdio.h>

int main()
{
  int c;
  int wordcnt=0, linecnt=0, alphacnt=0;
  while((c=getchar()) != EOF){
    alphacnt++;
    if(c==32){
      wordcnt++;
    }
    if(c==10){
      linecnt++;
      wordcnt++;
    }
  }
  printf("%d %d %d",++linecnt,++wordcnt,++alphacnt);
}
