#include <stdio.h>

int main(){
   int c = 0;
   scanf("%d", &c);
   int e = 0;
   int tem = 0;
    for(int l = 0;l == 0;){
        scanf("%d", &e);
        tem = tem + e;
        int partir = 2 * c;
        if(tem == 0){
            puts("vazio");
        }else if(tem < c){
            puts("ainda cabe");
        }else if(tem < partir){
            puts("lotado");
        }else{
            puts("hora de partir");
            l++;
        }
    }
}