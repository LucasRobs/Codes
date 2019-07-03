#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <SDL2/SDL.h>
#include "objeto.h"
//#include "tela.h"
#include "gconio.h"
int NL = 40;
int NC = 88;
int MAX = 9999;

int main(){
    int anterior = 0, timer = 0;
    FILE * ArqPost = fopen("level_1.txt", "r");
    Objeto * player = objeto_create(4, 5, '+', WHITE);
    Objeto * pedra = (Objeto*) realloc(pedra,sizeof(Objeto)*MAX);
    Objeto * poste = (Objeto*) realloc(poste,sizeof(Objeto)*MAX);
    Objeto * botao = (Objeto*) realloc(botao,sizeof(Objeto)*MAX);
    
    int IDposte = 0, IDbotao = 0, IDpedra = 0;
    char caractere;
    char corp[20];
    int l = 1, c = 1;
    while(fscanf(ArqPost,"%c",&caractere) == 1){
        if(caractere == '#'){
            poste[IDposte].x = c;
            poste[IDposte].y = l;
            poste[IDposte].nome = caractere;
            poste[IDposte].cor = YELLOW;
            IDposte += 1;
            c += 1;
        }else if(caractere == 'o'){
            botao[IDbotao].x = c;
            botao[IDbotao].y = l;
            botao[IDbotao].nome = caractere;
            botao[IDbotao].cor = BLUE;
            IDbotao += 1;
            c += 1;
        }else if(caractere == '@'){
            pedra[IDpedra].x = c;
            pedra[IDpedra].y = l;
            pedra[IDpedra].nome = caractere;
            pedra[IDpedra].cor = WHITE;
            IDpedra += 1;
            c += 1;
        }else if(caractere == '\n'){
            l += 1;
            c = 1;
        }else if(caractere == '.'){
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
        sprite(acao, player);
        //realizar logica de jogo
        objeto_move(player, acao);

        for(int i =0; i< IDposte; i++)
            if((player->x == poste[i].x) && (player->y == poste[i].y))
                *player = player_old;


        


        //quaaanddo alterar paraa vetor, colocaar isso aqui num for, ondee a pedra[i]->
        //ppedra__old deentro do for receebe pedra[i]
        //empurrar a pedra
        for(int i = 0; i < IDpedra; i++){
            if((player->x == pedra[i].x) && (player->y == pedra[i].y)){
                Objeto pedra_old = pedra[i];
                pedra[i].x -= player_old.x - player->x;
                pedra[i].y -= player_old.y - player->y;
                for(int i = 0; i < IDposte; i++)   //peddraa[i]
                    if((pedra[i].x == poste[i].x) && (pedra[i].y == poste[i].y)){
                        *pedra = pedra_old; 
                        *player = player_old;
                        sprite(acao, player);
                    }
            }
        }

        clrscr();

        //for  paara caadaaa pedra ver se ppedraa ta em cima de algum botao
            //see tiveer entao
                //paraa o vetor de portas, assim qq encontraarr uma porta fechada, aabra eela ee dddee um break
    
        for(int i = 0; i < IDposte; i++){
            objeto_print(&poste[i]);
        }
        for(int i = 0; i < IDbotao; i++){
            objeto_print(&botao[i]);
        }
        for(int i = 0; i < IDpedra; i++){
            objeto_print(&pedra[i]);
        }
        objeto_print(player);

        gotoxy(0, 0);
    }

    objeto_destroy(player);
    objeto_destroy(pedra);
    objeto_destroy(poste);
}