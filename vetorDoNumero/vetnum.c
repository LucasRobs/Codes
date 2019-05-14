#include <stdio.h>
#include <string.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    int size = strlen(num);
    int mod = 10;
    int aux = 0;
    int auxant = 0;
    int vet[size];
    for(int i = size;i >= 0;i--){
        aux = num % mod;
        if(i == size){
        vet[i] = aux;
        }
        aux = (num - auxant) % mod;
        mod = mod * 10;
        if(i != num){
            vet[i] = aux;
        }
        auxant = aux;
    }
    for(int i = 0;i < size;i++){
        printf("%d", vet[i]);
    }
}