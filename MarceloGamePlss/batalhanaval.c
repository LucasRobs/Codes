#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "gconio.h"
int main() {
    clrscr();
    textbackground(BLACK);
    int tabuleiro[5][5];
    int navios[3][2];
    int tiro[2];
    int tentativas = 0;
    int acertos = 0;
    iniciar_tabu(tabuleiro);
    iniciar_navios(navios);

    printf("\n");

    for(;acertos != 3;){
        show_tabu(tabuleiro);
        atirar(tiro);
        clrscr();
        tentativas++;

        if(acertou(tiro,navios)){
            dica(tiro,navios,tentativas);
            acertos++;
        }else
            dica(tiro,navios,tentativas);

        alterar_tabu(tiro,navios,tabuleiro);

        printacertos(acertos);
    }
    clrscr();   
    printf("\nJogo terminado. Voce teve 3 acertos em %d tentativas\n", tentativas);
    show_tabu(tabuleiro);
    puts("");
}