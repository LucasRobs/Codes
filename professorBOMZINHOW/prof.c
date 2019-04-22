#include <stdio.h>
int main(){
    float a = 0, b = 0, c = 0, d = 0;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    float x = 0;
    if(a <= b){
        if(b > c){
            x = (a + b + d) / 3;
            if(x >= 7){
                printf("Aprovado com %.1f\n",x);
            }else{
                printf("Final com %.1f\n",x);
            }
        }else{
            x = (a + c + d) / 3;
            if(x >= 7){
                printf("Aprovado com %.1f\n",x);
            }else{
                printf("Final com %.1f\n",x);
            }
        }
    }else if(b >= c){
        if(a >= c){
            x = (b + a + d) / 3;
            if(x >= 7){
                printf("Aprovado com %.1f\n",x);
            }else{
                printf("Final com %.1f\n",x);
            }
        }else{
            x = (b + c + d) / 3;
            if(x >= 7){
                printf("Aprovado com %.1f\n",x);
            }else{
                printf("Final com %.1f\n",x);
            }
        }
    }else if(c >= a){
        if(a >= b){
            x = (c + a + d) / 3;
            if(x >= 7){
                printf("Aprovado com %.1f\n",x);
            }else{
                printf("Final com %.1f\n",x);
            }
        }else{
            x = (c + b + d) / 3;
            if(x >= 7){
                printf("Aprovado com %.1f\n",x);
            }else{
                printf("Final com %.1f\n",x);
            }
        }
    }
}