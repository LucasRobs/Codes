#include <stdio.h>
int main(){
    int size = 0;
    scanf("%d", &size);
    int vet[size];
    int aux = 0;
    for(int i = 0; i < size; i++){
        scanf("%d", &vet[i]);
    }
    for(int i = 0; i < size; i++){
        if((vet[i] - vet[i+1]) == 1 ||(vet[i] - vet[i+1]) == -1 ||(vet[i] - vet[i+1]) == 0){
        }else{
        aux++;
        }
    }
    printf("%d", aux -1 );
}