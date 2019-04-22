#include <stdio.h>
#include <math.h>
int main(){
    int ces = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%i", &ces);
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    int tf = (a + b + c);
    int ro = tf / ces;
    int res = ces % tf;
    if(res >= 1){
        int ro = (tf / ces) + 1;
        printf("%i\n",ro);
    }else{
    printf("%i\n",ro);
}
}