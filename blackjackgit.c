#include <stdio.h>
int main(){
    int ncartas = 0;
    scanf("%d", &ncartas);
    int total = 0;
    int as = 0;
    int carta[ncartas];
    for(int i = 0;i < ncartas;i++){
        carta[i] = 0;
    }
    for(int i = 0;i < ncartas;i++){
        scanf("%d", &carta[i]);
        if(carta[i] > 9){
            carta[i] = 10;
        }
        if(carta[i] == 1){
            as++;
            total += 11;
        }else{
        total += carta[i];
        }
    }

    for(;total > 21 && as > 0;){
        total -= 10;
        as--;
    }
    printf("Histórico de cartas = [");
    for(int i = 0; i < ncartas; i++){
        if(carta[i] == 1)
            printf("A");
        else if(carta[i] == 11)
            printf("J");
        else if(carta[i] == 12)
            printf("Q");
        else if(carta[i] == 13)
            printf("K");
        else
            printf("%d", carta[i]);
        if(i != ncartas - 1)
            printf(", ");
    }
    printf("]\n");
    printf("total final %d\n", total);
}

