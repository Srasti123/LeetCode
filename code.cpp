#include <stdio.h>
int main()
{
  int i = 1;
  do{
    while(i++<1);
  }while(i++<=2);
  printf("%d",i);
}
