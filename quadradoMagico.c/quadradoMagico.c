#include <stdio.h>
int main(){
    int quadrado[3][3];
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            scanf("%d", &quadrado[x][y]);
        }
    }
    int hori[3]={ 0, 0, 0};
    int vert[3]={ 0, 0, 0};
    int diag[3]={ quadrado[0][0]+quadrado[1][1]+quadrado[2][2], quadrado[0][2]+quadrado[1][1]+quadrado[2][0], quadrado[0][2]+quadrado[1][1]+quadrado[2][0]};
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            hori[x] += quadrado[x][y];
        }
    }
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            vert[y] += quadrado[x][y];
        }
    }
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(hori[x] != vert[y] || hori[x] != diag[y]){
                puts("nao");
                return 0;
            }
        }
    }
    puts("sim");
}