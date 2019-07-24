#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gconio.h"
#include <unistd.h>
void load(){
    puts("/ ");clrscr();sleep(1);
    puts("- ");clrscr();sleep(1);
    puts("\\ ");clrscr();sleep(1);
    puts("| ");clrscr();sleep(1);
    puts("/ ");clrscr();sleep(1);
    puts("-");clrscr();sleep(1);
    puts("\\ ");clrscr();sleep(1);
    puts("| ");clrscr();sleep(1);
}

void caixa(int i){
    puts("");
    puts("");
    textcolor(i);
    puts("   ######  ####  ## ##    ## ######");
    puts("   ###### ###### ## ###  ### ######");
    puts("   ##     ##  ##     ######  ##  ##");
    puts("   ##     ###### ##    ##    ##  ##");
    puts("   ##     ###### ##   ####   ##  ##");
    puts("   ##     ##  ## ##  ######  ##  ##");
    puts("   ###### ##  ## ## ###  ### ######");
    puts("   ###### ##  ## ## ##    ## ######");
    puts("");
    textcolor(WHITE);
}

int main(){
    pid_t filho;
    filho = fork();
    char nav = '0';

    if(filho == 0){
        //load();
        while (1){
        nav = getch();
        }
        _exit(0);
    }else{
        int tabMenu[4] = {1, 0, 0, 0};
        int sprit = 1;
        while (1){
            if(nav == 'e')
                break;
            for(int i = 0; i < 5; i++){
                if(tabMenu[i] == 1){
                    if(nav == 'w' && i == 0){
                        tabMenu[3] = 1;
                        tabMenu[0] = 0;
                        break;
                    }else if(nav == 'w' && i != 0){
                        tabMenu[i - 1] = 1;
                        tabMenu[i] = 0;
                        break;
                    }

                    if(nav == 's' && i == 3){
                        tabMenu[0] = 1;
                        tabMenu[3] = 0;
                        break;
                    }else if(nav == 's' && i < 3){
                        tabMenu[i + 1] += 1;
                        tabMenu[i] = 0;
                        break;
                    }
                }
            }
            clrscr();

            caixa(sprit);
            sprit += 1;
            if(sprit > 15)
                sprit = 1;
            printf("         +==================+\n");
            printf("         |                  |\n");
            for(int i = 0;i < 4;i++){
                if(tabMenu[i] == 1){
                    printf("         |");
                    textcolor(RED);
                    printf(" => ");
                    textcolor(YELLOW);
                }else{
                    printf("         |   ");
                }
                if(i == 0)
                    printf("Jogar         ");
                else if(i == 1)
                    printf("Como Jogar    ");
                else if(i == 2)
                    printf("Creditos      ");
                else
                    printf("Sair          ");
                
                if(tabMenu[i] == 1){
                    textcolor(WHITE);
                    printf("|\n");
                }else
                    printf(" |\n");
            }
            printf("         |                  |\n");
            printf("         +==================+\n");
            sleep(1);
        }
        for(int i = 0; i < 4; i++){
            if(tabMenu[i] == 1){
                return i;
            }
        }
    }
}