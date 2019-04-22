#include <math.h>
#include <stdio.h>

int main(){
    int jog1 = 0;
    int jog2 = 0;
    int jog3 = 0;
    int jog4 = 0;
    scanf("%i", &jog1);
    scanf("%i", &jog2);
    scanf("%i", &jog3);
    scanf("%i", &jog4);
    int r = (jog1 + jog2 + jog3 + jog4) % 4;
    if (jog1 == 0 || jog2 == 0 || jog3 == 0 || jog4 == 0){
        puts("nenhum");
    }else if(jog1 != 2 || jog1 != 0 || jog2 != 2 || jog2 != 0 || jog3 != 2 || jog3 != 0 || jog4 != 2 || jog4 != 0){
        puts("nenhum");
    }else if(r == 1){
       puts("jog1");
    }else if(r == 2){
        puts("jog2");
    }else if(r == 3){
        puts("jog3");
    }else{
        puts("jog4");
    }
}