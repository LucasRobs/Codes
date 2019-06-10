#include <stdio.h>
#include <stdlib.h>
#include "objeto.h"
#include "gconio.h"

int NL = 15;
int NC = 50;

void draw_border(){
    for(int l = 0; l < NL; l++){
        gotoxy(0, l);
        printf("#");
        gotoxy(NC - 1, l);
        printf("#");
    }
    for(int c = 0; c < NC; c++){
        gotoxy(c, 0);
        printf("#");
        gotoxy(c, NL - 1);
        printf("#");
    }
    
}

int main(){
    Objeto * player = objeto_create(4, 5, '@', WHITE);
    Objeto * pedra = objeto_create(9, 3, '#', RED);
    Objeto * poste = objeto_create(9, 7, 'T', YELLOW);
    
    for(;;){
        //processar eventos
        char acao = ' ';
        acao = getch();
        if(acao == 'x'){    
            system("clear"); 
            puts("ADEUS ;-;");
            break;
        }
        //realizar logica de jogo
        objeto_move(player, acao);


        clrscr();
        draw_border();

        objeto_print(pedra);
        objeto_print(poste);
        objeto_print(player);

        gotoxy(0, 0);
    }

    objeto_destroy(player);
    objeto_destroy(pedra);
    objeto_destroy(poste);
}