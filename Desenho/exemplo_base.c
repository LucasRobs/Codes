#include "xpaint.h"

int main(){
    int largura = 1000, altura = 1000;
    /* cria um bitmap*/
    x_open(largura, altura); 
    /* muda a cor*/
    xs_color(BLACK);
    xd_filled_rect(0, 0, 1000, 1000);

    xs_color(RED);
    xd_thick_line(530, 400, 1000, 500, 25);
    xs_color(ORANGE);
    xd_thick_line(530, 425, 1000, 525, 25);
    xs_color(YELLOW);
    xd_thick_line(530, 450, 1000, 550, 25);
    xs_color(GREEN);
    xd_thick_line(530, 475, 1000, 575, 25);
    xs_color(BLUE);
    xd_thick_line(530, 500, 1000, 600, 25);
    xs_color(VIOLET);
    xd_thick_line(530, 525, 1000, 625, 25);


    xs_color(WHITE);
    xd_filled_triangle( 500, 300, 300, 700, 700, 700);
    xs_color(BLACK);
    xd_filled_triangle( 500, 319, 309, 691, 691, 691);    
    xs_color(WHITE);
    xd_thick_line(0, 600, 460, 460, 20);
   
    x_save("TDSOTM");
    x_close();
    return 0;
}