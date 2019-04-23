#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(){
    srand(time(NULL));
    int total = 0;
    int as = 0;
    int parada = 0;
    int size = 0;
    int carta = 0;
    int hist[20] = {0};
    for(int i = 0;i < 20;i++){
        hist[i] = 0;
    }
    for(int i = 0;i == parada;){
        printf("Nova carta foi : ");
        carta = rand() % (13 - 1 + 1) + 1;
        
        if(carta == 1)
            printf("A\n");
        else if(carta == 11)
            printf("J\n");
        else if(carta == 12)
            printf("Q\n");
        else if(carta == 13)
            printf("K\n"); 
        else
            printf("%d\n", carta); 
            
        if(carta > 9){
            carta = 10;
        }
        if(carta == 1){
            carta = 11;
            as++;
        }
        hist[i] = carta;
        total += carta;
        printf("Soma total : %d \n", total);
        if(total > 21){
            puts("VOCE È UM MERDA MERMÂO");
            break;
        }
        printf("Digite 0 = [hit] ou 1 = [parar]");
        scanf("%d", &parada);
        if(parada == 0){
            size++;
        }

        for(int x = total;total > 21 && as > 0;){
            total -= 10;
            as--;
        }
        
    }
    
    printf("Histórico de cartas = [");
    for(int i = 0; i <= size; i++){
        if(hist[i] == 1)
            printf("A");
        else if(hist[i] == 11)
            printf("J");
        else if(hist[i] == 12)
            printf("Q");
        else if(hist[i] == 13)
            printf("K");
        else
            printf("%d", hist[i]);
        if(i != size - 1)
            printf(", ");
    }
    printf("]\n");
    printf("total final %d\n", total);

}

