#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    if(n == 1){
        puts("1");
    }
    int contador = 0;
    int inpresora = 0;
    contador = n -1;
    contador--;
    for(int c = 0; c <= n - 2; c++){

            for(int x = 0; x <= contador; x++){
                printf(".");
            }
            for(int m = 0; m <= inpresora; m++){
                printf("%d.", n);
            }
            for(int x = 0; x <= (contador - 1); x++){
                printf(".");
            }
            inpresora++;
            contador--;
            puts("");
    }
    for(int b = 0; b <= n - 2; b++){
        if(b == 0){
            printf("%d", n);
        }
        printf(".%d", n);
    }
}