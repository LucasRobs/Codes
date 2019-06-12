#include <stdio.h>
#include <SDL2/SDL.h>
int main(){
int anterior = 0, timer = 0;
    while(1){
        timer = SDL_GetTicks();
        if (timer > anterior + 1000) {
            printf("TICK\n");
            anterior = timer;
        }
        //printf("%d ",timer);
    }
}


