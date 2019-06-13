/*
 * [Autor]
 * David Sena
 * sena.ufc@gmail.com
 *
 */

#ifndef TKIP_H
#define TKIP_H

/* Muda a cor da letra
 * r,g,b,y,c,m,k,w para cores claras
 * R,G,B,Y,C,M,K,W para cores escuras */
void tk_color(char color);

/* Limpa o fundo */
void tk_clear();

/* Escreve na posicao x,y o texto usando a sintaxe de printf
 * ex:  k_write(10,5,"oi");
 * ex:  k_write(12,6,"%d %c", idade, sexo); */
void tk_write(int x, int y, const char *format, ...);

/* Se houver alguma tecla no teclado ele retorna a tecla,
 * caso contrário, retorna 0  */
int tk_peek(void);

/* Trava e so retorna quando o usuario digitar uma tecla */
int tk_wait(void);

/* Faz o programa dormir por mseg, em milesegundos */
void tk_sleep(int msec);

/* Retorna um número aleatorio */
int  tkm_rand();

/* Toca um mp3 se tiver o programa mpg123 instalado */
void tk_mp3_play(char *path);

/* Interrompe um mp3 que esteja tocando */
void tk_mp3_stop(char *path);

/* Retorna o vetor com as 16 cores */
const char * tk_info_colors();

/*
 * [Autor]
 * David Sena
 * sena.ufc@gmail.com
 *
 */

#define _POSIX_C_SOURCE	199309L
#include <stdlib.h>//rand e srand
#include <stdio.h>
#include <unistd.h>
#include <termios.h>//k_peek e k_wait
#include <string.h>
#include <stdarg.h>//k_write
#include <sys/time.h>//srand e k_sleep
#include <time.h>//k_sleep


struct termios old_attr, new_attr;


void tk_color(char color)
{
    switch(color)
    {
        case 'k':
            printf("\033[1;30m");
            break;
        case 'r':
            printf("\033[1;31m");
            break;
        case 'g':
            printf("\033[1;32m");
            break;
        case 'y':
            printf("\033[1;33m");
            break;
        case 'b':
            printf("\033[1;34m");
            break;
        case 'm':
            printf("\033[1;35m");
            break;
        case 'c':
            printf("\033[1;36m");
            break;
        case 'w':
            printf("\033[1;37m");
            break;
        case 'K':
            printf("\033[0;30m");
            break;
        case 'R':
            printf("\033[0;31m");
            break;
        case 'G':
            printf("\033[0;32m");
            break;
        case 'Y':
            printf("\033[0;33m");
            break;
        case 'B':
            printf("\033[0;34m");
            break;
        case 'M':
            printf("\033[0;35m");
            break;
        case 'C':
            printf("\033[0;36m");
            break;
        case 'W':
            printf("\033[0;37m");
            break;
    }
}

const char * tk_info_colors(){
    static const char *colors = "rgbycmkwRGBYCMKW";
    return colors;
}

void tk_clear(){
    puts("\033[2J");
}

void tk_write(int x, int y, const char *format, ...)
{
    //corrigindo alinhamento
    y = y + 2;
    x = x + 1;

    char str[1000];   \
    va_list args;     \
    va_start( args, format );\
    vsprintf(str, format, args);\
    va_end( args );

    char msg[1000];
    sprintf(msg,"\033[%d;%dH%s",y,x,str);
    printf("%s",msg);
    printf("\033[500;500H");
}

/*
 * [Autor] k_peek e k_wait
 * Daemonio (Marcos Paulo Ferreira)
 * http://daemoniolabs.wordpress.com
 */
int tk_peek(void) {
    int c ;

    /* Obtém as configurações atuais. */
    tcgetattr(0,&old_attr);
    new_attr=old_attr;

    /* Desliga modo canônico. */
    new_attr.c_lflag &=~ICANON ;

    /* Desliga ecoamento. */
    new_attr.c_lflag &= ~ECHO;

    new_attr.c_cc[VTIME]=0 ;
    new_attr.c_cc[VMIN]=0 ;

    tcsetattr(STDIN_FILENO,TCSANOW,&new_attr);
    c = getchar() ; /* retorna EOF se nada foi pressionado */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);

    tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);
    if (c == EOF)
        c = 0;
    return c ;
}

/*
 * [Autor] khit e kwait
 * Daemonio (Marcos Paulo Ferreira)
 * http://daemoniolabs.wordpress.com
 */
int tk_wait(void) {
    int c ;
    /* Obtém as configurações atuais. */
    tcgetattr(0,&old_attr);
    new_attr=old_attr;

    /* Desliga modo canônico. */
    new_attr.c_lflag &=~ICANON ;

    /* Espera indefinidamente até
     * que um byte seja lido. */
    new_attr.c_cc[VTIME]=0 ;
    new_attr.c_cc[VMIN]=1 ;
    /* Desliga ecoamento. */
    new_attr.c_lflag &= ~ECHO;

    /* Chama getchar() que realizará somente a
     * leitura de um byte, devido o terminal
     * não estar em modo canônico quando ela
     * é chamada. */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_attr);
    c = getchar() ;
    tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);

    tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);
    return c ;
}

void tk_sleep(int msec)
{
    puts(" ");
    struct timespec interval;
    struct timespec remainder;
    interval.tv_sec = msec / 1000;
    interval.tv_nsec = (msec % 1000) * (1000 * 1000);
    nanosleep(&interval, &remainder) ;
    //usleep(1000*msec);
}

int tkm_rand()
{
    static int init = 1;
    if(init) {
        init = 0;
        srand(time(NULL));
    }
    return rand();
}

void tk_mp3_play(char *path){
    char c[500];
    sprintf(c,"mpg123 %s 2>/dev/null 1>/dev/null&",path);
    system(c);
}

void tk_mp3_stop(char *path){
    char c[500];
    sprintf(c,"ps aux  | grep \"mpg123 %s\" |head -1|  awk '{ print $2; }' | xargs kill -9 2>/dev/null 1>/dev/null&",path);
    system(c);
}

#endif

/* EOF */
