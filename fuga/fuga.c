#include <stdio.h>
int main(){
    int h= 0;
    int p= 0;
    int f= 0;
    int d= 0;
    scanf("%d %d %d %d", &h, &p, &f, &d);
    if(d == -1){
        
        for (int c = f ; c != h ; c++){
            if(f == p - 1){
                puts("S");
                break;
            }
            if(f == h - 1){
                puts("N");
                break;
            }
            if(f == 15){
                f == 0;
            }
        }
    }else if(d == 1){
        for (int c = f ; c != h ; c--){
            if(f == p + 1){
                puts("S");
                break;
            }
            if(f == h + 1){
                puts("N");
                break;
            }
            if(f == 0){
                f == 15;
            }
        }
    }
}