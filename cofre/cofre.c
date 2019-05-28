#include <stdio.h>
int main(){
	int size = 0, hits = 0;
	scanf("%d %d",&size,&hits);
	int vet[size];
	for(int i =0; i< size; i++){
		scanf("%d", &vet[i]);
	}
    int vet2[9];
    for(int i =0; i <= 9;i++){
        vet2[i] =0;
    }
int atual = 0 ,anterior = 0 ,novo = 0;
 for(int i = 0; i < hits;i++){
    scanf("%d", &novo);
    if(atual > novo){
        for(;atual != novo ;atual--){
           vet2[vet[atual]]++;
        }
     }
    
    else{
        for(;atual != novo ;atual++){
           vet2[vet[atual]]++;
        }
    }
 }
 
    for(int i =0; i <= 9;i++){
        printf("%d", vet2[i]);
    }
 }