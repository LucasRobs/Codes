    #include <stdio.h>
    #include <math.h>
    int main(){
        int c = 0;
        scanf("%d", &c);
        int a = 1;
        int b = 1;
        int s = 0;
        for(int q = 0; q <= c - 3; q++){
            if(c == 1 || c == 2){
                puts("1");
            }
            s = b + a;
            a = b;
            b = s;
            if(q == c-3){
                printf("%d\n", s);
            }
        }
    }