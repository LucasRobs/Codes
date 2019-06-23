#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int main(){
    srand(time(NULL));
    Tabela * cartela = (Tabela*) realloc(cartela,sizeof(Tabela)*2);
    //int Ncartelas = 2;
    //scanf(" %c", &Ncartelas);
    for(int i = 0; i < 2;i++){
        char nomeC = '0';
        scanf(" %c",&nomeC);
        Tabela[i].nome = nomeC;
    } 
    //Tabela * cartela = Tabela_create('a');
    //Tabela * cartela1 = Tabela_create('b');
    int novoNumero = 0, Nbolas = 0, urna[75];
    for(int i = 0; i < 75; i++){
        urna[i] = 0;
    }
    while(1){
        system("cls");
        for(int i = 0; i < 2;i++)
            Tabela_print(cartela[i]);
        int ganhou = bingo(cartela);
        if(ganhou == 0){
            puts("FIMM");
            return 0;
        }
        novoNumero = rand() %  75 + 1;
        Nbolas += 1;
        for(int i = Nbolas; i > 0; i--){
            if(novoNumero == urna[i]){
                novoNumero = rand() %  75 + 1;
                i = Nbolas;
            }
        }
        urna[Nbolas -1] = novoNumero;
        for(int i = 0; i < 2;i++)
        temNumero(novoNumero, cartela[i]);
        
        sleep(2);

        for(int i = 0; i < Nbolas; i++){
            printf("%d ", urna[i]);
        }
        puts("");
    }
    
}