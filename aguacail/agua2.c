#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <locale.h>
#include "lib.h"

int main(){
    int acao = 0;
    setlocale(LC_ALL, "Portuguese");
    while(1){
        printf("Digite 1 para pedir água, digite 2 para sair.\n");
        scanf("%d", &acao);
        if(acao == 2){
            break;
        }
        else if(acao == 1){
            pedir_agua(ID);
        }
       ID += 1;

    }
}