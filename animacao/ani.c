#include "gconio.h"
#include <stdlib.h>

int main(){
    int var[9] = {1,2,3,4,5,6,7,8,9};
    int i = 0;
    while(1){
        printf(" %d",var[i]);
        i++;
        sleep(1);
    }
}