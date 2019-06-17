#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <SDL2/SDL.h>
#include "objeto.h"
//#include "tela.h"
#include "gconio.h"
int NL = 15;
int NC = 50;
int MAX = 9999;

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

bool esta_sobre_cerca(Objeto * obj){
    return (obj->x == 1 || obj->x == NC - 1 || obj->y == 1 || obj->y == NL - 1);
}
//bool esta_sobre_plat(Plataforma * plat){}        

int main(){
    int anterior = 0, timer = 0;
    FILE * ArqPost = fopen("poste.txt", "r");
    Objeto * player = objeto_create(4, 5, '+', WHITE);
    Objeto * pedra = objeto_create(9, 3, '#', YELLOW);
    Objeto * poste = (Objeto*) realloc(poste,sizeof(Objeto)*2);
    //for(int i =0;i< 3;i++){
    //poste = objeto_create(9, 7, 'G', YELLOW);
    //(poste+1) = objeto_create(3, 4, 'G', YELLOW);
    //for(int i = 0;i < plataformas;i++)
    
    
    int xp = 0;
    int yp  = 0;
    int Npostes = 0;
    char nomep = '0';
    char corp[20];
    fscanf(ArqPost,"%d", &Npostes);
    for(int i = 0; i < Npostes;i++){
        fscanf(ArqPost,"%d %d %c %s", &xp, &yp, &nomep, &corp);
        poste[i].x = xp;
        poste[i].y = yp;
        poste[i].nome = nomep;
        poste[i].cor = corp;
    }
    
/*
    poste[0].x = 9;
    poste[0].y = 7;
    poste[0].nome = 'G';
    poste[0].cor = "WHITE";
    
    poste[1].x = 3;
    poste[1].y = 4;
    poste[1].nome = 'X';
    poste[1].cor = "WHITE";
*/  

    while(1){
        //processar eventos
        char acao = ' ';
        
        //timer = SDL_GetTicks();
        acao = getch();
        //if (timer > anterior + 1000) {
        //    acao = 's';
        //    anterior = timer;
        ///}
        if(acao == 'q')
            break;


        Objeto player_old = *player;
        Objeto pedra_old = *pedra;

        //realizar logica de jogo
        objeto_move(player, acao);

        if(esta_sobre_cerca(player))
            *player = player_old;
        for(int i =0; i< Npostes; i++){
        if((player->x == poste[i].x) && (player->y == poste[i].y))
            *player = player_old;
        }
        //empurrar a pedra
        if((player->x == pedra->x) && (player->y == pedra->y)){
            pedra->x -= player_old.x - player->x;
            pedra->y -= player_old.y - player->y;
        }

        if(esta_sobre_cerca(pedra)){
            *player = player_old;
            *pedra = pedra_old;
        }
        


        clrscr();
        draw_border();

        objeto_print(pedra);
        for(int i = 0; i < Npostes; i++){
            objeto_print(&poste[i]);
        }
        objeto_print(player);

        gotoxy(0, 0);
    }

    objeto_destroy(player);
    objeto_destroy(pedra);
    objeto_destroy(poste);
}