#include <stdio.>
int main(){
    char frase[100];
    int digitos[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6};
    int x = 0, contador = 0;
    scanf("%d", &x);
    for(int i = 0;i < x; i++){
        scanf("%s", frase);
        int n = strlen(frase);
        for(int z = 0;z < n;z++){
            contador += digitos[frase[z]];
        }
    }
}