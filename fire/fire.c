#include <stdio.h>
#include <time.h> 
#include "gconio.h"
const int fogoLargura = 18;
const int fogoAltura = 18;

void rederizaFogo(int fogotab[]){
    int pont = 0;
    for(int y = 0; y < fogoAltura; y++){
        for(int x = 0; x < fogoLargura; x++){
            textcolor(fogotab[pont] % 15);
            printf("%.2d ", fogotab[pont]);
            pont++;
        }
        puts("");
    }
}

void fonteFogo(int fogotab[]){
    for(int i = 0; i < fogoLargura; i++){
        int ultimoPixel = ((fogoAltura * fogoLargura) - fogoLargura) + i;
        fogotab[ultimoPixel] = 36;
    }
}

void propagarFogo(int fogotab[]){
    for(int x = 0; x < fogoAltura; x++){
        for(int y = 0; y < fogoLargura; y++){
            int point = x + (fogoLargura * y);
            int pixelBaixo = point + fogoLargura ;
            int declinio = (rand() % 3) + 1;


            if(y == fogoAltura - 1){}
            else if(fogotab[pixelBaixo] == 0){}
            else{
                int oudFogo = fogotab[point];
                fogotab[point] = fogotab[pixelBaixo - 1] - declinio;
                if((fogotab[point] - declinio) < 0){
                   fogotab[point] = oudFogo; 
                }
            }
        }
    }
}


int main(){
    srand(time(NULL));
    int fogoTab[fogoAltura * fogoLargura];
    int numeroDePixels =  fogoAltura * fogoLargura;
    for(int i = 0; i  < numeroDePixels; i++){
        fogoTab[i] = 0;
    }
    fonteFogo(fogoTab);
    for(int i = 0;i <  500; i++){
    clrscr();
    propagarFogo(fogoTab);
    rederizaFogo(fogoTab);
    sleep(1);
    }
}