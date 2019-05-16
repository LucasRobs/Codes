#include <stdio.h>


int proximo(int i, int size, int vet[]){
    int aux = (i + 1) % size;
    while(vet[aux] == 0){
        aux = (aux + 1) % size;
    }
    return aux;
}


int main(){
    int size = 0, escolhido = 0;
    scanf("%d %d", &size ,&escolhido);
    int vet[size];
    int aux = size;
    escolhido--;

    for(int i = 0; i < size; i++){
        vet[i] = i + 1;
    }
    while(aux > 1){
        int morto = proximo(escolhido,size,vet);
        vet[morto] = 0;
        escolhido = proximo(morto,size,vet);
        aux--;
    }
    for(int i = 0;i < size;i++){
        if(vet[i] != 0){
            printf("%d", vet[i]);
        }
    }
}