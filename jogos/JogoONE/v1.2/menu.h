#pragma once
#include <stdio.h>
#include "gconio.h"

void caixa(int i){
    puts("");
    puts("");
    textcolor(i);
    puts("   ######  ####  ## ##    ## ######");
    puts("   ###### ###### ## ###  ### ######");
    puts("   ##     ##  ##     ######  ##  ##");
    puts("   ##     ###### ##    ##    ##  ##");
    puts("   ##     ###### ##   ####   ##  ##");
    puts("   ##     ##  ## ##  ######  ##  ##");
    puts("   ###### ##  ## ## ###  ### ######");
    puts("   ###### ##  ## ## ##    ## ######");
    puts("");
    textcolor(WHITE);
}


int menu(){
    char nav = '0';
    int tabMenu[4] = {1, 0, 0, 0};
    int sprit = 1;
    while (1){
        nav = getch();
        if(nav == 'e')
            break;
        for(int i = 0; i < 5; i++){
            if(tabMenu[i] == 1){
                if(nav == 'w' && i == 0){
                    tabMenu[3] = 1;
                    tabMenu[0] = 0;
                    break;
                }else if(nav == 'w' && i != 0){
                    tabMenu[i - 1] = 1;
                    tabMenu[i] = 0;
                    break;
                }

                if(nav == 's' && i == 3){
                    tabMenu[0] = 1;
                    tabMenu[3] = 0;
                    break;
                }else if(nav == 's' && i < 3){
                    tabMenu[i + 1] += 1;
                    tabMenu[i] = 0;
                    break;
                }
            }
        }
        clrscr();

        caixa(sprit);
        sprit += 1;
        if(sprit > 15)
            sprit = 1;
        printf("         +==================+\n");
        printf("         |                  |\n");
        for(int i = 0;i < 4;i++){
            if(tabMenu[i] == 1){
                printf("         |");
                textcolor(RED);
                printf(" => ");
                textcolor(YELLOW);
            }else{
                printf("         |   ");
            }
            if(i == 0)
                printf("Jogar         ");
            else if(i == 1)
                printf("Como Jogar    ");
            else if(i == 2)
                printf("Creditos      ");
            else
                printf("Sair          ");
            
            if(tabMenu[i] == 1){
                textcolor(WHITE);
                printf("|\n");
            }else
                printf(" |\n");
        }
        printf("         |                  |\n");
        printf("         +==================+\n");
    }
    for(int i = 0; i < 4; i++){
        if(tabMenu[i] == 1){
            return i;
        }
    }
}

void comoJogar(){
    printf("         +===================+\n");
    printf("         | W ^ Cima          |\n");
    printf("         | A < Esquerda      |\n");
    printf("         | S v Baixo         |\n");
    printf("         | D > Direita       |\n");
    printf("         |                   |\n");
    printf("         | E - Selecionar    |\n");
    printf("         | Q - Sair do Jogo  |\n");
    printf("         |                   |\n");
    printf("         |       E -> Jogar  |\n");
    printf("         |       Q -> Voltar |\n");
    printf("         +===================+\n");
}
void creditos(){
    printf("         +======================+\n");
    printf("         | Criador : Lucas Robs |\n");
    printf("         |                      |\n");
    printf("         | Com axilio de :      |\n");
    printf("         |   Paulo Henrique     |\n");
    printf("         |   David Sena         |\n");
    printf("         |   Emanuel            |\n");
    printf("         |                      |\n");
    printf("         |          E -> Jogar  |\n");
    printf("         |          Q -> Voltar |\n");
    printf("         +======================+\n");
}