#include <stdio.h>
int main(){
    int size = 0;
    scanf("%d", &size);
    int vet[size];
    int aux = 1;
    int maior = -1;
    for(int i = 0;i < size;i++){
        scanf("%d", &vet[i]);
        if(maior < vet[i])
            maior = vet[i];
    }
    int cont[maior];
    for(int i = 0;i < maior;i++){
        cont[i] = 0;
    }
    for(int i = 0;i < size;i++){
        cont[vet[i]]++;
    }
    for(int i = 0;i < maior;i++)
        if(cont[i] > 0){
            aux++; 
        }
    
    printf("%d", aux);
}