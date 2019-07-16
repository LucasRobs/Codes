#pragma once
#include <stdlib.h>
#include "gconio.h"

typedef struct{
    int x, y;
    char nome;
    int cor;
} Objeto;

Objeto * objeto_create(int x, int y, char nome, int cor){
    Objeto * obj = (Objeto*) malloc(sizeof(Objeto));
    (*obj).x = x;
    obj->y = y;
    obj->nome = nome;
    obj->cor = cor;
    return obj;
}

void objeto_destroy(Objeto * obj){
    free(obj);
}

void objeto_move(Objeto * obj, char dir){
    if(dir == 'a')
        obj->x -= 1;
    else if(dir == 'd')
        obj->x += 1;
    else if(dir == 'w')
        obj->y -= 1;
    else if(dir == 's')
        obj->y += 1;
}
void sprite(char acao, Objeto * obj){
    if(acao == 's'){
        obj->nome = 'v';
    }else if(acao == 'w'){
        obj->nome = '^';
    }else if(acao == 'a'){
        obj->nome = '<';
    }else if(acao == 'd'){
        obj->nome = '>';
    }
}

void objeto_print(Objeto * obj){
    textcolor(obj->cor);
    gotoxy(obj->x, obj->y);
    printf("%c", obj->nome);
}

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
void imprime_mapa(int IDposte, Objeto* poste,int IDbotao, Objeto* botao, int IDpedra, Objeto* pedra, Objeto* player, Objeto* fim){
    for(int i = 0; i < IDposte; i++){
        objeto_print(&poste[i]);
    }
    for(int i = 0; i < IDbotao; i++){
        objeto_print(&botao[i]);
    }
    for(int i = 0; i < IDpedra; i++){
        objeto_print(&pedra[i]);
    }
    objeto_print(fim);
    objeto_print(player);
}

int fim_de_jogo(Objeto* player,Objeto* fim){
    if(player->x == fim->x && player->y == fim->y){
        clrscr;
        puts("aaa");
        return 1;
    }
}