typedef struct{
    char nome;
    int tabela[5][5];
} Tabela;

Tabela * Tabela_create(char nome){
    Tabela * tab = (Tabela*) malloc(sizeof(Tabela));
    tab->nome = nome;
    int maior = 0, menor = 0, fase[5]={15,30,45,60,75};
    for(int y = 0;y < 5;y++){
        maior = fase[y];
        menor = maior - 14;
        for(int x = 0; x < 5; x++){
            tab->tabela[x][y] = rand() % (maior - menor + 1) + menor;
            for(int z = x - 1;z >= 0; z--){
                if(tab->tabela[x][y] == tab->tabela[z][y]){
                    tab->tabela[x][y] = rand() % (maior - menor + 1) + menor;
                    z = x - 1;
                }
            }
        }
    }
    return tab;
}  

void Tabela_print(Tabela * tab){
    printf("[B][I][N][G][O]\n");
    for(int x = 0;x < 5;x++){
        for(int y = 0; y < 5; y++){
            if(tab->tabela[x][y] == 0){
                printf("|X ");
            }else{
                printf("|%02d", tab->tabela[x][y]);
            }
        }
        puts("|");
    }
}

void temNumero(int novoNumero,Tabela * tab){
    for(int x = 0;x < 5;x++){
        for(int y = 0; y < 5; y++){
            if(novoNumero == tab->tabela[x][y]){
                tab->tabela[x][y] = 0;
            }
        }
    }
}

int bingo(Tabela * tab){
    for(int x = 0;x < 5;x++){
        for(int y = 0; y < 5; y++){
            if(tab->tabela[x][0] == 0 && ){
                return 0;
            }
            if(tab->tabela[0][y] == 0)
            if(tab->tabela[0][0] == 0)
            if(tab->tabela[x][y] != 0){
                return 1;
            }
        }
    }
    return 0;
}
