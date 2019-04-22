#include <stdio.h>
#include<stdlib.h>
int main (){
    int entrada = 0;
    int temp = 0;
    scanf("%d", &entrada);
    for(int i = 1; temp != entrada; i++){
        temp = (rand() % 1000) + 1;
        if(temp != entrada){
            printf("%d errou com %d tentativas\n", temp, i);
        }else{
            printf("%d acertou com %d tentativas\n", temp, i);
        }
    }
    return 0;
}