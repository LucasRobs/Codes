#include <stdio.h>
int main(){
    int a = 0, b = 0, c = 0, h = 0, l = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &h, &l);
    int aux1 = a * b;
    int aux2 = a * c;
    int comp = h * l;
    if(aux1 < comp || aux2 < comp){
        puts("S");
    }else{
        puts("N");
    }
}