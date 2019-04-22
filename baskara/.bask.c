#include <math.h>
#include <stdio.h>

float main(){
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    float delta = sqrt(pow(b, 2) - 4 * a * c);
    
    float bask1 = - (b * b) + delta / 2 * a;
    float bask2 = - pow(b, 2) - sqrt(pow(b, 2) - 4 * a * c) / 2 * a;
    
    printf("%.2f\n%.2f\n", bask1, bask2);
}