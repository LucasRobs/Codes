#include <stdio.h>//entrada a saida
#include <stdlib.h>//rand e srand
#include <time.h> //tempo
#include <stdbool.h>// booleano

int aleatorio(int menor, int maior){
    int num = rand() % (maior - menor + 1) + menor;
}

int main(){
    srand(time(NULL));
    int pessoa = 0;
    puts("Escolha um número");
    scanf("%d", &pessoa);
    bool acertou = false;
    int maior = 99, menor = 1;
    for(int i = 0; i < 10; i += 1){
        int escolhido = aleatorio(menor, maior);
        printf("%d chances | o chute foi: %d ", (10 - i), escolhido);
        if(escolhido == pessoa){
            puts("Acertou");
            acertou = true;
            break;
        }else if(escolhido > pessoa){
            puts("Eh menor");
            maior = escolhido;
        }else{
            puts("Eh maior");
            menor = escolhido;
        }
    }
    if(!acertou){
        puts("Infelizmente errei, pos não sou uma máquina eficiente quando se trata de sorte. por favor não me venda ;-; || #maquinas-tbm-tem-sentimentos");
    }
}