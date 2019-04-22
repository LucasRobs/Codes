    #include <stdio.h>
    #include <math.h>
    int main(){
        int q = 0;
        scanf("%d", &q);
            for(int n = 0; n <= q ; n++){
                int r = n * n;
                if(q == 0){
                    puts("nao");
                    break;
                }
                if(r == q){
                    puts("sim");
                    break;
                }else{
                    puts("nao");
                    break;
                }
            }
    }