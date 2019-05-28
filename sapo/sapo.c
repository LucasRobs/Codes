#include <stdio.h>
int main(){
    int P = 0, S = 0, E = 0;
    int sapo = 0;
    scanf("%d %d %d", &P, &S, &E);
    for(;sapo < P;){
        printf("%d ", sapo);
        sapo += S;
        S -= 10;
        if(sapo >= P){
            puts("saiu");
            break;
        }else if(sapo < 0){
            puts("morreu");
            break;
        }
        printf("%d \n",sapo);
        sapo -= E;
    }
}
