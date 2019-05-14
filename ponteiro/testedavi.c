#include <stdio.h>


int main(){
    int vet_add(int vet[], int *size, int value){
        vet[*size] = value;
        *size += 1;
    }
    int vet[1000];
    int size = 0;
    for(int i = 0;i != -1;i++){
        int valor = 0;
        scanf("%d", &valor);
        if(valor == -1){
            break;
        }
        vet_add(vet, &size, valor);
    }
}