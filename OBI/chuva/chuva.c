#include <stdio.h>
int main(){
    int L = 0, C = 0;
    scanf("%d %d", &L, &C);
    char M[C][L];
    for(int x = 0; x < L; x++){
        for(int y = 0; y < C; y++){
            scanf("%c", &M[x][y]);
        }
    }
    while(1){
        for(int x = 0; x < L; x++){
            for(int y = 0; y < C; y++){
                if(M[x][y] == 'o'){
                    if(M[x][y+1] == '#'){
                        M[x+1][y] = 'o';
                        M[x-1][y] = 'o';
                        
                    }else if(M[x][y+1] == '.'){
                        M[x][y+1] = 'o';
                    }
                }
            }
        }
        for(int x = 0; x < C; x++){
            if(M[x][L] == 'o'){
                for(int x = 0; x < L; x++){
                    for(int y = 0; y < C; y++){
                        printf(" %c", M[x][y]);
                        return 0;
                    }
                }
            } 
        }
    }
}