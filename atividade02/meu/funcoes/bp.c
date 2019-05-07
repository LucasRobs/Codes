#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(){
    int aleatorioEntre(int menor,int maior);
    void letraDaCarta(int carta);
    void mostrarHist(int x, int hist[]);
    void mostrarHistM(int x, int histM[]);
    int money = 100;
    for(int rodada = 1;money > 0;rodada++){
    srand(time(NULL));
    int total = 0;
    int totalM = 0;
    int as = 0;
    int parada = 0;
    int size = 1;
    int sizeM = 1;
    int carta = 0;
    int hist[20] = {0};
    int histM[20] = {0};
    int aposta = 0;
    for(int i = 0;i < 20;i++){
        hist[i] = 0;
        histM[i] = 0;
    }
    for(int i = 0;i != -1;i++){
        if(i == 0){
            if(money < 5){
                puts("Você não pode mais apostar #semGranaIrmão");
                return 0;
            }
            printf("Rodada [%d]\nDinheiros : %d \nDigite valor da aposta ou -1 para sair : ", rodada, money);
            for(;aposta <= 5 || aposta > 100 || aposta >= money;){
                scanf("%d", &aposta);
                if(aposta == -1){
                    puts("Volte sempre!");
                    return 0;
                }
                if(aposta <= 5 || aposta > 100 || aposta >= money){
                    puts("Digite valor menor que 100$ e maior que 5$");
                }
                money = money - aposta;
            }
        }
        if(i > 1)
            size++;
        if(i == 0){
            printf("Mesa recebe [");
        }else{
            printf("Voce recebe [");
        }
        carta = aleatorioEntre(1,13);
        letraDaCarta(carta);
        printf("]");
        if(i == 0)
            histM[i] = carta;
        else
            hist[i - 1] = carta;
        if(carta > 9){
            carta = 10;
        }
        if(carta == 1){
            carta = 11;
            as++;
        }
        if(i == 0){
            totalM += carta;
            printf(" - Total %d [ ", totalM);
            for(int x = 0; x < size; x++)
                mostrarHistM(x, histM);
        }else{
            total += carta;
            printf(" - Total %d [ ", total);
            for(int x = 0; x < size; x++)
                mostrarHist(x, hist);
        }
        printf("]\n");
        if(total > 21){
            puts("Voce perdeu!");
            break;
        }
        if(i == 0){
            //jogada da mesa
        }else if(i < 2){
            //2x jogada do player
        }else{
            printf("Hit 0 ou Parar 1 : ");
            scanf("%d", &parada);
        }
        if(parada == 1){
            size++;
            break;
        }
        for(;total > 21 && as > 0;){
            total -= 10;
            as--;
        }   
    }

        for(int i = 0;total <= 21;i++){
            if(totalM > 21){
                puts("Voce Ganhou!");
                money = money + (2 * aposta);
                break;
            }else if(totalM == 21 || totalM >= total){
                puts("Voce perdeu!");
                break;
            }
            sizeM++;
            printf("Mesa recebe [");
            carta = aleatorioEntre(1,13);
            letraDaCarta(carta);
            printf("]");  
            histM[i + 1] = carta;
            if(carta > 9)
                carta = 10;
            if(carta == 1){
                carta = 11;
                as++;
            }
            totalM += carta;
            printf(" - Total %d [ ", totalM);
            for(int x = 0; x < sizeM; x++){
                    mostrarHistM(x, histM);
            }
            printf("]\n");
            printf("Seu histórico de cartas = [ ");
            for(int x = 0; x < size -1; x++){
                mostrarHistM(x, hist);
            }
            printf("]\nHistórico de cartas da mesa = [ ");
            for(int x = 0; x <= sizeM -1; x++){
                mostrarHistM(x, histM);
            }
            printf("]\n");
        }

    printf("Seu total final %d\n", total);
    printf("Total final da mesa %d\n", totalM);
    }
}
int aleatorioEntre(int menor, int maior){
    int num = rand() % (maior - menor + 1) + menor;
    return num;
}
void letraDaCarta(int carta){
    if(carta == 1)
            printf("A");
        else if(carta == 11)
            printf("J");
        else if(carta == 12)
            printf("Q");
        else if(carta == 13)
            printf("K"); 
        else
            printf("%d", carta);    
}
void mostrarHist(int x, int hist[]){
    if(hist[x] == 1)
            printf("A ");
        else if(hist[x] == 11)
            printf("J ");
        else if(hist[x] == 12)
            printf("Q ");
        else if(hist[x] == 13)
            printf("K "); 
        else
            printf("%d ", hist[x]);
}
void mostrarHistM(int x, int hist[]){
    if(hist[x] == 1)
            printf("A ");
        else if(hist[x] == 11)
            printf("J ");
        else if(hist[x] == 12)
            printf("Q ");
        else if(hist[x] == 13)
            printf("K "); 
        else
            printf("%d ", hist[x]);
}