#include <stdio.h>
int main(){
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int r = 0;
  scanf ("%d", &n1);
  scanf ("%d", &n2);
  scanf ("%d", &n3);
    if (n1 == n2){
        r += 1;
    };
    if (n1 == n3){
        r += 1;
    };
    if (n2 == n3){
       r += 1;
    };
    if( r == 1){
        r += 1;
        printf("%d \n", r);
    }else{
      printf("%d \n", r);
    };
  return 0;
}