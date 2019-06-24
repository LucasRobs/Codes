#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lib.h"

int main(){
    srand(time(NULL));
    Tabela * cartela = Tabela_create('a');//cria tabela
    int novoNumero = 0, Nbolas = 0, urna[75];//var
    for(int i = 0; i < 75; i++){//zera a urna
        urna[i] = 0;
    }
    while(1){ //laço 
        //system("cls");
        
        Tabela_print(cartela);//printa tabela
        int ganhou = bingo(cartela);//confere se todos numeros são 0 na tabela
        if(ganhou == 0){
            printf("gerou %d bolas", Nbolas);// diz quantas bolas tem no final
            puts("");
            return 0;
        }
        novoNumero = rand() %  75 + 1;//gera o novo numero sorteado 
        Nbolas += 1;
        if(Nbolas == 70){
            puts("perdeu playboy"); // < msg que perdeu
            return 0;
        }
        for(int i = Nbolas; i > 0; i--){//confere se tem numero igual
            if(novoNumero == urna[i]){
                novoNumero = rand() %  75 + 1;
                i = Nbolas;
            }
        }
        urna[Nbolas -1] = novoNumero;// escreve no vetor o novo numero  
        temNumero(novoNumero, cartela);//confere se o novo numero tem na tabela
        
        //sleep(1);//teminho pra gerar bolas

        for(int i = 0; i < Nbolas; i++){
            printf("%d ", urna[i]);//printa a urna
        }
        puts("");// \n
    }
    
}