#include <stdio.h>
#include <stdlib.h>//rand e srand
#include <time.h> //time
#include <stdbool.h>



int rand_int_fechado(int menor, int maior){
    int num = rand() % (maior - menor + 1) + menor;
}

int main(){
    srand(time(NULL));
    bool acertou = false;
        int numero = 0;
        puts("seu numero :");
        scanf("%d", &numero);
        int maior = 999, menor = 1;
    for(int i = 0; i < 10; i += 1){
        int escolhido = rand_int_fechado(menor, maior);
        printf("eu escolhi %d", escolhido);
        printf(" e voc tem %d chances. ", (10 - i));
        if(escolhido == numero){
            puts("Acertou!\n");
            acertou = true;
            break;
        }else if(escolhido > numero){
            puts("Eh menor!\n");
            maior = escolhido;
            getchar();
        }else{
            puts("Eh maior!\n");
            menor = escolhido;
            get_char();
        }
    }
    if(!acertou){
        puts("Errou");
    }
}
