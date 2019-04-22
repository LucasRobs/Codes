#include <math.h>
#include <stdio.h>

int main(){
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    float p = (a + b + c) / 2;
    float ar = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.02f\n", ar);
}