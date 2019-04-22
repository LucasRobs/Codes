#include <stdio.h>

int main(){
    int p = 0;
    int s = 0;
    int e = 0;
    scanf("%d %d %d",&p ,&s ,&e);
    int c = 0;
    int sx = 0;
    sx += s;
    for(int l = sx; l <= p ;){
        if(c == 0){
            printf("%d %d\n", c, s);
        }
        c = sx - e;
            printf("%d %d\n", c, sx);
        
    }
    
}