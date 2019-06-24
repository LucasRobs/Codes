#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <SDL2/SDL.h>
#include "objeto.h"
//#include "tela.h"
#include "gconio.h"
int NL = 38;
int NC = 88;
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
    FILE * ArqPost = fopen("level_1.txt", "r");
    Objeto * player = objeto_create(4, 5, '+', WHITE);
    Objeto * pedra = objeto_create(9, 3, '#', WHITE);
    Objeto * poste = (Objeto*) realloc(poste,sizeof(Objeto)*MAX);
    Objeto * botao = (Objeto*) realloc(botao,sizeof(Objeto)*MAX);
    
    int xp = 0;
    int yp  = 0;
    int IDposte = 0, IDbotao = 0;
    char nomep;
    char corp[20];
    int l = 1, c = 0;
    while(fscanf(ArqPost,"%c",&nomep) == 1){
        if(nomep == '#'){
            poste[IDposte].x = c;
            poste[IDposte].y = l;
            poste[IDposte].nome = nomep;
            poste[IDposte].cor = YELLOW;
            IDposte += 1;
            c += 1;
        }else if(nomep == 'o'){
            botao[IDbotao].x = c;
            botao[IDbotao].y = l;
            botao[IDbotao].nome = nomep;
            botao[IDbotao].cor = BLUE;
            IDbotao += 1;
            c += 1;
        }else if(nomep == '\n'){
            l += 1;
            c = 0;
        }else if(nomep == '.'){
            c += 1;
        }
    }
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
        sprite(acao, player);
        //realizar logica de jogo
        objeto_move(player, acao);

        if(esta_sobre_cerca(player))
            *player = player_old;
        for(int i =0; i< IDposte; i++)
            if((player->x == poste[i].x) && (player->y == poste[i].y))
                *player = player_old;


        //empurrar a pedra
        if((player->x == pedra->x) && (player->y == pedra->y)){
            pedra->x -= player_old.x - player->x;
            pedra->y -= player_old.y - player->y;
        }
        
        for(int i =0; i< IDposte; i++)
            if((pedra->x == poste[i].x) && (pedra->y == poste[i].y)){
                *pedra = pedra_old; 
                *player = player_old;
                sprite(acao, player);
            }

        if(esta_sobre_cerca(pedra)){
            *player = player_old;
            *pedra = pedra_old;
        }


        


        clrscr();
        //draw_border();

    
        for(int i = 0; i < IDposte; i++){
            objeto_print(&poste[i]);
        }
        for(int i = 0; i < IDbotao; i++){
            objeto_print(&botao[i]);
        }
        objeto_print(pedra);
        objeto_print(player);

        gotoxy(0, 0);
    }

    objeto_destroy(player);
    objeto_destroy(pedra);
    objeto_destroy(poste);
}