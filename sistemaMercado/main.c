#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gerente.h"
#include "cliente.h"

int main(){
    int tamanho = 0;
    while(true){
        Produto * produtos = lerBanco(&tamanho);
        int utilizador = 0;
        puts("[1]GERENTE|[2]CLIENTE");
        scanf("%d", &utilizador);
        switch(utilizador){
            case 1:
                if(login())
                produtos = menu(produtos,&tamanho);
                escreverBanco(produtos,tamanho);
                break;
            case 2:
                produtos = menucliente(produtos,&tamanho);
                escreverBanco(produtos,tamanho);
                break;
            default:
                puts("comando invalido");
                break;
        }
    }
}
