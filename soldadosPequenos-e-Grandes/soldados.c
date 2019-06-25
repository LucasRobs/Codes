#include <stdio.h>
int media(int vet[], int qtd){
    int media;
    for(int i = 0;i < qtd;i++){
        media += vet[i];
    }
    media = media / qtd;
    return media;
}
int main(){
    int qtd = 0;
    scanf("%d", &qtd);
    float vet[qtd];
    int mediana = 0;
    for(int i = 0;i < qtd;i++){
        scanf("%f", vet[i]);
    }
    mediana = media(vet,qtd);
    printf("%d", mediana);
}