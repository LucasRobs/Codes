#include <stdio.h>
int main(){
    int size = 0;
    scanf("%d", &size);
    int tamanho = 0;
    char pe = 0;
    int vet[size];
    int sizeE = 0;
    int sizeD = 0;
    int vetE[size];
    int vetD[size];
    for(int i = 0;i < size;i++){
        scanf("%d %c", &tamanho, &pe);
        if(pe == 'E'){
            vetE[i] = tamanho;
            sizeE++;
        }
        if(pe == 'D'){
            vetD[i] = tamanho;
            sizeD++;
        }
    }
    int aux = 0;
    for(int i = 0; i < sizeE;i++){
        for(int x = 0; x < sizeD;x++){
            if(vetE[i] == vetD[x]){
                aux++;
                vetD[x] = -1;
            }
        }
    }
    printf("%d", aux);
    return 0;
}