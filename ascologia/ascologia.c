#include <stdio.h>
#include <string.h>
int main(){
    char nome[100];
    scanf("%s", nome);
    int n = strlen(nome);
    int soma = 0;

    for(int i = 0;i < n;i++){
        soma += nome[i];
    }
    printf("%d\n", soma % 50);
    return 0;
}