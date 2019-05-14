#include <stdio.h>

int main(){
    void ordenador(int * vet, int size);
    int vet[] = { 4, 7, 8, 2, 6, 1, 9, 4}, size = sizeof(vet)/sizeof(int);
    ordenador(*vet,size);
    for(int i = 0;i < size;i++){
        printf("%d", vet[i]);
    }
}

void ordenador(int * vet, int size){
    
}