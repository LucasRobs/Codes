#include <stdio.h>//entrada a saida
#include <stdlib.h>//rand e srand
#include <time.h> //tempo
#include <stdbool.h>// booleano

int aleatorio(int menor, int maior){
    int num = rand() % (maior - menor + 1) + menor;
}

int main(){
    srand(time(NULL));
    int maior = 1000, menor = 1;
    int maquina = rand() % (maior - menor + 1) + menor;
    printf("a maquina escolheu : %d\n", maquina);
    for(int i = 0;;){
        int escolhido = aleatorio(menor, maior);
        printf("chute numero %d | o chute foi: %d ", (i++), escolhido);
        if(escolhido == maquina){
            puts("Acertou");
            break;
        }else if(escolhido > maquina){
            puts("Eh menor");
            maior = escolhido;
        }else{
            puts("Eh maior");
            menor = escolhido;
        }
    }
}