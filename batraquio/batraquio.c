#include <stdio.h>
#include <stdbool.h>
int main(){
    int cont1 = 0, cont2 = 0;
    int vet1[50];
    int vet2[50];
    scanf("%d", &cont1);
    for(int i = 0;i < cont1; i++){
        scanf("%d", vet1[i]);
    }
    scanf("%d", &cont2);
    for(int i = 0;i < cont2; i++){
        scanf("%d", vet2[i]);
    }
    for(int i = 0; i < cont1; i++){
        for(int x = 0; x < cont2 ; x++){
            if(vet1[i] == vet2[x]){
                break;
            }else if(vet1[i] != vet2[cont2 - 1]){
                puts("não");
                return 0;
            }
        }
    }
    puts("sim");
}