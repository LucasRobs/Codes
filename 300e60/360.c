#include <stdio.h>
int main(){
    int a = 0;
    scanf("%d", &a);
    int b = a % 360;
    if (a < 0){
    b += 360;
    int c = b % 360;
    printf("%d", c);
    }else{
    printf("%d", b);
    }
}