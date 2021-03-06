
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gconio.h"
#include "objeto.h"
//#include "menu.h"

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

void draw_platform(){
    for(int i = 5;i<10;i++){
        gotoxy(i, 8);
        printf("A");
    }
}

bool esta_sobre_cerca(Objeto * obj){
    return (obj->x == 1 || obj->x == NC - 1 || obj->y == 1 || obj->y == NL - 1);
}
        

int main(){
    while(1){
    //int menu =  menu();
    //if(menu = 1){
        Objeto * player = objeto_create(4, 5, '@', WHITE);
        Objeto * pedra = objeto_create(9, 3, '#', RED);
        Objeto * poste = objeto_create(9, 7, 'T', YELLOW);
        
        while(1){
            //processar eventos
            char acao = ' ';
            acao = getch();

            if(acao == 'q')
                return 0;

            Objeto player_old = *player;
            Objeto pedra_old = *pedra;

            //realizar logica de jogo
            objeto_move(player, acao);

            if(esta_sobre_cerca(player))
                *player = player_old;

            if((player->x == poste->x) && (player->y == poste->y))
                *player = player_old;
            
            //empurrar a pedra
            if((player->x == pedra->x) && (player->y == pedra->y)){
                pedra->x -= player_old.x - player->x;
                pedra->y -= player_old.y - player->y;
            }
            //pedra no poste
            //if((pedra->x == poste->x) && (pedra->y == poste->y)){
            //    Objeto * pedra = NULL;
            //    Objeto * pedra = objeto_create(2, 2, '#', RED);
            //}

            if(esta_sobre_cerca(pedra)){
                *player = player_old;
                *pedra = pedra_old;
            }
            


            clrscr();
            draw_border();
            draw_platform();

            objeto_print(pedra);
            objeto_print(poste);
            objeto_print(player);

            gotoxy(0, 0);
        }

        objeto_destroy(player);
        objeto_destroy(pedra);
        objeto_destroy(poste);
    //}else if(menu == 2){
    //  int creditos = creditos(void);
    //}
}
}