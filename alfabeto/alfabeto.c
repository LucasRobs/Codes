#include <stdio.h>
#include <stdlib.h>

int main () {
    char c;
    int i = 0;
    scanf("%d", &i);
    for (c = 96; c < 122; c++){
        if(c + i == 96){
            puts("joguem de novo");
            break;
        }else if(c == (((i + 1) % 26) + 97) && c < (i + 122)){
            printf("%c", c);
        }
    }
}