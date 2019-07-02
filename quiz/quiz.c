#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gconio.h"

typedef struct{
    int IDpergunta;
    char perg[9999];
    char itemA[100];
    char itemB[100];
    char itemC[100];
    char itemD[100];
    char itemE[100];
    char resposta;
} Pergunta;

void pergunta_print(Pergunta * per){
    for(int i = 0;i < 9999;i++){
        printf("%c",per->perg[i]);
        }
    puts("");
    for(int i = 0;i < 100;i++){
        printf("%c",per->itemA[i]);
    }
    puts("");
    for(int i = 0;i < 100;i++){
        printf("%c",per->itemB[i]);
    }
    puts("");
    for(int i = 0;i < 100;i++){
        printf("%c",per->itemC[i]);
    }
    puts("");
    for(int i = 0;i < 100;i++){
        printf("%c",per->itemD[i]);
    }
    puts("");
    for(int i = 0;i < 100;i++){
        printf("%c",per->itemE[i]);
    }
    puts("");
    printf("%c", per->resposta);
}

int main(){
    int IDpergunta = 0;
    char lper[9999];
    char itemA[100];
    char itemB[100];
    char itemC[100];
    char itemD[100];
    char itemE[100];
    char resposta;
    int n = 0;
    FILE * ArqPerguntas = fopen("perguntas.txt", "r");
    Pergunta * perg = (Pergunta*) realloc(perg,sizeof(Pergunta)*9999);
    for(int i = 0; i < 2;i++){
        while(fscanf(ArqPerguntas,"%[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %c", lper, itemA, itemB, itemC, itemD, itemE, &resposta) == 1){
            perg[IDpergunta].IDpergunta = IDpergunta;
            n = strlen(lper);
            for(int i = 0; i < n; i++)
                perg[IDpergunta].perg[i] = lper[i];
            n = strlen(itemA);
            for(int i = 0; i < n; i++)
                perg[IDpergunta].itemA[i] = itemA[i];
            n = strlen(itemB);
            for(int i = 0; i < n; i++)    
                perg[IDpergunta].itemB[i] = itemB[i];
            n = strlen(itemC);
            for(int i = 0; i < n; i++)
                perg[IDpergunta].itemC[i] = itemC[i];
            n = strlen(itemD);
            for(int i = 0; i < n; i++)
                perg[IDpergunta].itemD[i] = itemD[i];
            n = strlen(itemE);
            for(int i = 0; i < n; i++)
                perg[IDpergunta].itemE[i] = itemE[i];
            perg[IDpergunta].resposta = resposta; 
            IDpergunta += 1;
        }
    }
    for(int i = 0; i < 2; i++)
        pergunta_print(&perg[i]);
}