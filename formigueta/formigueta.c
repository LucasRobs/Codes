#include <stdio.h>
int main(){
    int h = 0;
    int m = 0;
    char d = '0';
    int cm = 0;
    int auh = 0;
    int aum = 0;
    scanf("%d %d %c %d", &h, &m, &d, &cm);
    auh = h * 6;
    aum = m / 10;
    int soma = auh + aum;
    if(d == 'H'){
            soma = (soma + cm) % 72;

    }else if(d == 'A'){
        soma = (soma - cm) % 72;
        if(soma < 0){
            soma += 72;
        }
    }
    auh = soma / 6;
    aum = (soma % 6) * 10;
    printf("%02d %02d", auh, aum);
}