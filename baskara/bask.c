#include <math.h>
#include <stdio.h>

int main(){
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    float delta = pow(b, 2) - ((4 * a) * c);
  
    float bask1 = (- b + sqrt(delta)) / (2 * a);
    float bask2 = (- b - sqrt(delta)) / (2 * a);
    if(delta > 0){
        printf("%.2f\n%.2f\n", bask1, bask2);
    }else if(delta == 0){
        printf("%.2f\n", bask1);
    }else{
        puts("nao ha raiz real");
}
}