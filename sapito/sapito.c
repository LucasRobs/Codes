#include <stdio.h>
int main(){
    int P = 0, S = 0, E = 0;
    int sapo = 0;
    scanf("%d %d %d", &P, &S, &E);
    for(;sapo < P && sapo >= 0;){
        printf("%d ", sapo);
        sapo += S;
        S -= 10;
        sapo -= E;
        if(sapo > P){
            puts("sail");
            break;
        }
        printf("%d\n",sapo);
    }
}