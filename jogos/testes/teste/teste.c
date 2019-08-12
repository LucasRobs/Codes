#include <stdio.h>
#include "gconio.h"
#include "kbhit.h"
#include <stdbool.h>
#include <stdlib.h>
int main(){
    char c;

    for(;;){
        printf("hello\n");
        if(_kbhit()){
            c = getch();
            printf("%c\n", c);
        }
    }
    return 0;
}