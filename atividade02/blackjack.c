#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
char nome_da_carta(int carta){
    if(carta == 1)
        return 'A';
    else if(carta == 10)
        return 'f'; // letra que representa o 10 
    else if(carta == 11)
        return 'J';
    else if(carta == 12)
        return 'Q';
    else if(carta == 13)
        return 'K';
    else
        return carta + '0'; 
}

int valor_as(int soma){
    if(soma > 21){
        return soma -10;
    }else{
        return soma;
    }
}

void print(char vet[]){
    for(int i =0;vet[i] != '0' && vet[i] != '\0';i++){
        if(vet[i] == 'f'){
            printf("10 ");
        }else{
            printf("%c ", vet[i]);
        }
    }
}
void verifica_10(char dez){
    if(dez == 'f')
        printf("10");
    else   
        printf("%c", dez);
    
}
int main(){
    char maoM[21], maoJ[21];
    for(int i = 0;i < 21; i++)
        maoM[i] = maoJ[i] = '0';
    srand(time(NULL));
    int mesa = (rand() % 13) + 1,cartaM = 0,cartaJ = 0;
    int somaM = mesa, somaJ = 0; 
    maoM[0] = nome_da_carta(somaM);
    printf("# Mesa recebe ");
    verifica_10(maoM[0]);
    printf(" - Total %d [ ",maoM[0],somaM);
    print(maoM);
    printf("]\n");

    return 0; 
}