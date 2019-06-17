#include <stdio.h>
#include <string.h>
int main(){
    char frase[100];
    char letra[1];
    int contador = 0;
    scanf("%s %s", frase, letra);
    int n = strlen(frase);
    
    for(int i = 0;i<n;i++){
        if(frase[i] == letra[0])
            contador++;
    }
    printf("%d -- \n", letra[0]);
    printf("%d", contador);
}
