#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "objeto.h"
//#include "tela.h"
#include "gconio.h"
int NL = 40;
int NC = 88;
int MAX = 4000;

void destruir_postes(int l, Objeto* postes, int *t, Objeto* portas, int *t2, int k){
    for(int i = l ; i < *t-1; i++){
        postes[i] = postes[i+1];
    }
    *t = *t - 1;
    for(int i = k; i < *t2 - 1; i++){
        portas[i] = portas[i + 1];
    }
    *t2 = *t2-1;
}
void imprime_mapa(int IDposte, Objeto* poste,int IDbotao, Objeto* botao, int IDpedra, Objeto* pedra, Objeto* player){
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
}


int main(){
    int anterior = 0, timer = 0;
    FILE * ArqPost = fopen("level_1.txt", "r");
    FILE * ArqLogi = fopen("logic_1.txt", "r");
    Objeto * player = objeto_create(9, 2, '+', WHITE);
    Objeto * pedra = (Objeto*) malloc(sizeof(Objeto)*MAX);
    Objeto * poste = (Objeto*) malloc(sizeof(Objeto)*MAX);
    Objeto * botao = (Objeto*) malloc(sizeof(Objeto)*MAX);

    int IDposte = 0, IDbotao = 0, IDpedra = 0;
    char caractere;
    char corp[20];
    int l = 1, c = 1;
    while(fscanf(ArqPost,"%c",&caractere) == 1){
        if(caractere == '#' || caractere == '=' || caractere == '|'){
            poste[IDposte].x = c;
            poste[IDposte].y = l;
            poste[IDposte].nome = caractere;
            if (caractere == '=' || caractere == '|')
                poste[IDposte].cor = RED;
            else
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
            pedra[IDpedra].nome = 'ࠈ';
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
    Objeto * portas = (Objeto*) malloc(sizeof(Objeto)*MAX);
    int botao_visitados[IDbotao];
    for(int i = 0; i < IDbotao;i++){
        botao_visitados[i] = 0;
    }
    int IDportas = 0, c2 = 0, l2 = 0;

    for(int i = 0; i < 3; i++){
        scanf("%d %d", &c2 ,&l2);
        portas[IDportas].x = l2;
        portas[IDportas].y = c2;
        portas[IDportas].nome = '#';
        portas[IDportas].cor = RED;
        IDportas += 1;
    }

    /* while(fscanf(ArqLogi,"%d %d", &c2, &l2) == 1){
            portas[IDportas].x = l2;
            portas[IDportas].y = c2;
            portas[IDportas].nome = '#';
            portas[IDportas].cor = RED;
            IDportas += 1;
    }*/
    while(1){
        //processar eventos
        char acao = ' ';
        acao = getch();
        if(acao == 'q')
            break;
        
        Objeto player_old = *player;
        sprite(acao, player);
        //realizar logica de jogo
        objeto_move(player, acao);

        for(int i =0; i< IDposte; i++)
            if((player->x == poste[i].x) && (player->y == poste[i].y))
                *player = player_old;


        for(int i = 0; i < IDpedra; i++){
            if((player->x == pedra[i].x) && (player->y == pedra[i].y)){
                Objeto pedra_old = pedra[i];
                pedra[i].x -= player_old.x - player->x;
                pedra[i].y -= player_old.y - player->y;
                for(int j = 0; j < IDposte; j++)
                    if((pedra[i].x == poste[j].x) && (pedra[i].y == poste[j].y)){
                        *pedra = pedra_old;
                        *player = player_old;
                        sprite(acao, player);
                    }
            }
        }
        clrscr();
        
        for(int i = 0; i < IDpedra; i++){
            bool achou = false;
            for(int j = 0; j < IDbotao; j++){
                if((botao[j].x == pedra[i].x) && (botao[j].y == pedra[i].y) && (botao_visitados[j] == 0)){
                    for(int k = 0; k < IDportas; k++){
                        for(int l = 0; l < IDposte; l++){
                            if((portas[k].x == poste[l].x) && (portas[k].y == poste[l].y)){
                                destruir_postes(l, poste, &IDposte, portas, &IDportas, k);
                                achou = true;
                                botao_visitados[j] = 1; 
                            }
                            if(achou)
                                break;
                       }
                        if(achou)
                            break;
                   }
                    if(achou)
                        break;
                }
                if(achou)
                    break;
            }
            if(achou)
                break;
        }
        //for  paara caadaaa pedra ver se ppedraa ta em cima de algum botao
            //see tiveer entao
                //paraa o vetor de portas, assim qq encontraarr uma porta fechada, aabra eela ee dddee um break
        imprime_mapa(IDposte, poste,IDbotao, botao, IDpedra, pedra, player);
        
        gotoxy(0, 0);
    }

    objeto_destroy(player);
    objeto_destroy(pedra);
    objeto_destroy(poste);
}
