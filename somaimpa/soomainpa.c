#include <stdio.h>

int main(){
   int a = 0;
   int b = 0;
   scanf("%d %d", &a, &b);
   int s = 0;
   if(a > b)
        puts("invalido");
    else{
        for(int i = a ; i <= b ; i++){
            if((i % 2) != 0)
                s += i;
        }
        printf("%d", s);
    }
   
}