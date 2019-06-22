#include <stdio.h>
int main(){
    char fase[50];
    int Nfrases = 0;
    int cont = 0, oudcont = 0, inicio = 0;
    scantf("%d", &Nfrases);
    for(int i = 0 ; i < Nfrases; i++){
        scanf("%s", &frase)
        int n = stdlen(frase);
        for(int x = 0; x < n; x++){
            if(frase[x] == 'a' ||frase[x] == 'e' ||frase[x] == 'i' ||frase[x] == 'o' || frase[x] == 'u'){
                for(;;){
                    oudcont ++;
                    if(frase[x] != 'a' ||frase[x] != 'e' ||frase[x] != 'i' ||frase[x] != 'o' || frase[x] != 'u'){
                        if(cont < oudcont){
                            cont = oudcont;
                            inicio = x;
                        }
                        break;

                    }
                }
            }
        }
        for(int i = x;x < n+oudcont;x++){
            printf("%c",frase[i]);
        }
    }
}