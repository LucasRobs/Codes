#pragma once

#include <stdlib.h>
#include "gconio.h"

typedef struct{
    int x, y;
    char nome;
    int cor;
} Plataforma;

Plataforma * plataforma_create(int x, int y, char nome, int cor){
    Plataforma * plat = (Plataforma*) malloc(sizeof(Plataforma));
    plat->x = x;
    plat->y = y;
    plat->nome = nome;
    plat->cor = cor;
    return plat;
}

void plataforma_destroy(Plataforma * plat){
    free(plat);
}

void objeto_print(Plataforma * plat){
    textcolor(plat->cor);
    gotoxy(plat->x, plat->y);
    printf("%c", plat->nome);
}