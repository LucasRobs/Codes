#include <stdio.h>
int main(){
    int numero = 0;
    scanf("%d", numero);
    for(int i = 2; i < numero ;i++){
        if((nomero % i) != 0){
            puts("1");
            return 0;
        }
    }
    puts("0");
}