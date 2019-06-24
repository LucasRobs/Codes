#include <stdio.h>

int main(){
    int size = 0, escolhido = 0;
    scanf("%d %d", &size, &escolhido);
    int vet[size];
    for(int x = 0; x < size; x++){
        scanf("%d", &vet[x]);
    }
    int escolhidos[escolhido]
    for(int x = 0; x < escolhido; x++){
        scanf("%d", escolhidos[x]);
    }
    for(int y = 0;y < escolhido;y++){
        for(int x = 0;x < size; x++){
            if(vet[x] == escolhidos[y]){
                vet[x - 1] = vet[x - 1] * -1; 
                vet[x + 1] = vet[x + 1] * -1;
            }
        }
    }
    for(int x = 0; x <= size; x++){
        if(x == 0 ){
            printf("[");
        }
        if(x == (size)){
            printf("]\n");
        }else if(x == size - 1){
        printf("%d", vet[x]);
        }else{
        printf("%d ", vet[x]);
        }
    }
}