#include <stdio.h>
int main(){
    int size =0;
    scanf("%d", &size);
    int vet[size];
    int vetinv[size];
    for(int i = 0;i < size;i++){
        scanf("%d", &vet[i]);
    }
    for(int i = size - 1;i >= 0;i--){
        int x = 0;
        x++;
        vetinv[x] = vet[i];
        printf("%d ", vetinv[x]);
    }
}