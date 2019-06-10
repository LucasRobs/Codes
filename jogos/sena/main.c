#include <stdio.h>
#include "tk.h"
int main(void) {

  int x = 10;
  int y = 10;
  int mx = 2;
  int my = 0;

  while(1){
    char c = tk_peek();
    if(c == 'a'){
      mx = -2; my = 0;
    }else if(c == 'd'){
      mx = 2; my = 0;
    }else if(c == 'w'){
      mx = 0; my = -1;
    }else if(c == 's'){
      mx = 0; my = 1;
    }else if(c == '.'){
      mx = 0; my = 0;
    }
    x += mx;
    y += my;

    tk_clear();
    tk_color('r');
    tk_write(0, 0, "Use asdw para mudar a direcao e . para parar");
    tk_color('g');
    tk_write(x, y, "oi");
    tk_sleep(500);
  }
}