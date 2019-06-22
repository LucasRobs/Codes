#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct{
    char nome;
    int tabela[5][5];
} Tabela;

Tabela * Tabela_create(char nome){
    Tabela * tab = (Tabela*) malloc(sizeof(Tabela));
    tab->nome = nome;
    int maior = 0, menor = 0, fase[5]={15,30,45,60,75};
    for(int y = 0;y < 5;y++){
        maior = fase[y];
        menor = maior - 14;
        for(int x = 0; x < 5; x++){
            tab->tabela[x][y] = rand() % (maior - menor + 1) + menor;
            for(int z = x - 1;z >= 0; z--){
                if(tab->tabela[x][y] == tab->tabela[z][y]){
                    tab->tabela[x][y] = rand() % (maior - menor + 1) + menor;
                    if(tab->tabela[x][y] == tab->tabela[z][y])
                        tab->tabela[x][y] = rand() % (maior - menor + 1) + menor;
                }
            }
        }
    }
    return tab;
}  

void Tabela_print(Tabela * tab){
    printf("[B][I][N][G][O]\n");
    for(int x = 0;x < 5;x++){
        for(int y = 0; y < 5; y++)
            printf("|%02d", tab->tabela[x][y]);
        puts("|");
    }
}


int main(){
    srand(time(NULL));
    Tabela * cartela = Tabela_create('a');
    Tabela_print(cartela);
}