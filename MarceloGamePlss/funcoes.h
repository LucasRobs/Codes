#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gconio.h"
void iniciar_tabu(int tabuleiro[][5]){ //função para iniciar o tabuleiro.
    for(int linha = 0; linha < 5; linha ++)
        for(int coluna = 0 ;coluna < 5; coluna++ )
            tabuleiro[linha][coluna] = -1;
}

void show_tabu(int tabuleiro[][5]){ //função para mostrar o tabuleiro.
    textcolor(WHITE);
    printf("  1 2 3 4 5");
    printf("\n");
    char letra[5] = {'A', 'B', 'C', 'D', 'E'};
    for(int linha=0 ; linha < 5 ; linha++){
        textcolor(WHITE);
        printf("%c", letra[linha]);
        for(int coluna = 0 ; coluna < 5 ; coluna++){
            textcolor(BLUE);
            if(tabuleiro[linha][coluna]== -1){
                    printf(" ~");
            }else if(tabuleiro[linha][coluna] == 0){
                    textcolor(RED);
                    printf(" *");
            }else if(tabuleiro[linha][coluna] == 1){
                    textcolor(RED);
                    printf(" X");
            }

        }
        printf("\n");
    }

}

void iniciar_navios(int navios[][2]){
    srand(time(NULL));
    for(int navio = 0 ;navio < 3 ;navio++){
        navios[navio][0] = rand() % 5;
        navios[navio][1] = rand() % 5;

        for(int anterior = 0; anterior < navio; anterior++){
            if((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1]))
                do{
                    navios[navio][0] = rand() % 5;
                    navios[navio][1] = rand() % 5;
                }while((navios[navio][0] == navios[anterior][0]) && (navios[navio][1] == navios[anterior][1]));
            }

        }
    }          
void atirar(int tiro[2]){
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'a', 'b', 'c', 'd', 'e'}, coluna = '0';
    textcolor(WHITE);
    printf("Linha Coluna: ");
    for(int b = 0; b != 1;){
        scanf("%c %d", &coluna, &tiro[1]);
        for(int i = 0; i < 10; i++){
            if(coluna == linha[i] && tiro[1] > 0 && tiro[0] < 5){
                tiro[0] = i % 5;
                b += 1;
            }
        }
        puts("letra ou numero invalido");
        printf("Linha Coluna: ");
    }
    for(int i = 0; i < 10; i++){
        if(coluna == linha[i]){
            tiro[0] = i % 5;
        }
    }
    tiro[1] -= 1;
}

int acertou(int tiro[2], int navios[][2]){  
    char letra[5] ={'A', 'B', 'C', 'D', 'E'};
    for(int navio = 0; navio < 3; navio++){
        if( tiro[0] == navios[navio][0] && tiro[1] == navios[navio][1]){
            printf("+----------------------------+\n..Voce acertou o tiro (%c,%d)..\n+----------------------------+\n",letra[tiro[0]],tiro[1]+1);
            return 1;
        }
    }
    printf("+----------------------------+\n..Voce Errou o tiro em (%c,%d)..\n+----------------------------+\n",letra[tiro[0]],tiro[1]+1);
    return 0;
}

void printacertos(int acertos){
    printf("..navios %d/3..\n+------------+\n", acertos);
}

void dica(int tiro[2], int navios[][2], int tentativa){
    int linha = 0;
    int coluna = 0;
    char letra[5] = {'A', 'B', 'C', 'D', 'E'};
    //conta quantos navios há na linha tiro[0]
    for(int fila = 0 ; fila < 3 ; fila++){
        if(navios[fila][0]==tiro[0])
            linha++;
        if(navios[fila][1]==tiro[1])
            coluna++;
    }
    clrscr();
    printf("\nDica %d: \nlinha %c tem %d navios\ncoluna %d tem %d navios\n",tentativa,letra[tiro[0]],linha,tiro[1]+1,coluna);
}

void alterar_tabu(int tiro[2], int navios[][2], int tabuleiro[][5]){
    if(acertou(tiro,navios)){
        tabuleiro[tiro[0]][tiro[1]] = 1;
        printf("(%c,%d)", tiro[0], tiro[1]);
    }
    else
        tabuleiro[tiro[0]][tiro[1]] = 0;
}