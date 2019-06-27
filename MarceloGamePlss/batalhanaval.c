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

    do{
        show_tabu(tabuleiro);
        atirar(tiro);
        clrscr();
        tentativas++;

        if(acertou(tiro,navios)){
            dica(tiro,navios,tentativas);
            acertos++;
        }
        else
            dica(tiro,navios,tentativas);

        alterar_tabu(tiro,navios,tabuleiro);


    }while(acertos != 3);
    clrscr();   
    printf("\n\n\nJogo terminado. Voce teve 3 acertos em %d tentativas\n", tentativas);
    show_tabu(tabuleiro);
    puts("");
}