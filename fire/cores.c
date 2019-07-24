#include <stdio.h>
#include <time.h> 
#include "gconio.h"
int main(){
    for(int i = 0 ; i <= 15; i++){
        textcolor(i);
        printf("%d Lucas", i);
        puts("");
    }
    textcolor(0);
    printf("Lucas");
    for(int i = 0 ; i <= 7; i++){
        textbackground(i);
        printf("/");
        textbackground(0);
        puts("");
    }
    int x = get_screen_columns();
    int y = get_screen_rows();
    textbackground(7);
    printf("%d %d", x, y);
    for(int i = 0; i < 10; i++){
        getche();
    }
    textbackground(0);
}