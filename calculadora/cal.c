#include <stdio.h>
int main(){
   int a = 0;
   int b = 0;
   char s = 0;
   scanf("%d %d %c", &a, &b, &s);
   if(s == '+'){
        int r = a + b;
        printf("%d", r);
   }else if(s == '-'){
        int r = a - b;
        printf("%d", r);
   }else if(s == '*'){
        int r = a * b;
        printf("%d", r);
   }else{
       if(b == 0){
           puts("invalida");
       }else{
        int r = a / b;
        printf("%d", r);
       }
   }   
}