
#include <stdio.h>
#include <stdlib.h>
#include "gconio.h"
#include "objeto.h"
#include "tela.h"


int main(){
    Objeto * player = objeto_create(4, 5, '@');
    Objeto * pedra = objeto_create(9, 7, '#');
    Objeto * poste = objeto_create(10, 8, 'T');

    char tela[NL][NC];
    for(;;){
        char acao = getch();
        //scanf("%c", &acao);
        if(acao == 'x'){
            system("clear"); 
            puts("ADEUS ;-;");
            return 0;
        }
        system("clear");  
        objeto_move(player, acao);

        tela_clear(tela);
        tela_draw_border(tela);

        tela_draw_object(tela, player);
        tela_draw_object(tela, pedra);
        tela_draw_object(tela, poste);

        tela_print(tela);
    }
    objeto_destroy(player);
    objeto_destroy(pedra);
    objeto_destroy(poste);
}