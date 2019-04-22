#include <stdio.h>
#include <stdlib.h>//rand e srand
#include <time.h> //time
#include <stdbool.h>



int rand_int_fechado(int menor, int maior){
    int num = rand() % (maior - menor + 1) + menor;
}

int main(){
    int g = 0;
    srand(time(NULL));
    bool acertou = false;
        int numero = 0;
        puts("seu numero :");
        scanf("%d", &numero);
        int maior = 999, menor = 1;
    for(int i = 0; i < 10; i += 1){
        int escolhido = rand_int_fechado(menor, maior);
        if(escolhido == numero){
            puts("Acertou! ");
            acertou = true;
            g = i;
            break;
        }else if(escolhido > numero){
            puts("Eh menor! ");
            maior = escolhido;
        }else{
            puts("Eh maior! ");
            menor = escolhido;
        }
        printf("voc tem %d chances.\n ",(10 - i));
        printf("%d\n", escolhido);
    }
    if(!acertou){
        puts("Errou");
    }
    if(acertou){
        if(g == 0){
            puts("você é o Chuck Noris.");
        }else if(g < 4){
            puts("você é o Chapolin.");
        }else if(g < 9){
            puts("você é o Jaspion.");
        }else{
            puts("você é cagado.");
        }
    }
}
