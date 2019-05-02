#include <stdio.h>
int main(){
    int size = 0;
    int maior = 0;
    int menor = 0;
    scanf("%d", &size);
    scanf("%d %d", &menor, &maior);
    int vet[size];
    int aux = 0;
    for(int i = 0;i < size;i++){
        scanf("%d", &vet[i]);
        if(vet[i] < maior && vet[i] > menor){
            aux++;
        }
    }
    printf("%d", aux);
}