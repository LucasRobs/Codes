#define MAX_CHAR 100
int cont = 0;
int ID = 0;

typedef struct{
    char nome[MAX_CHAR];
    char rua[MAX_CHAR];
    char bairro[MAX_CHAR];
    int num;
} Endereco;

Endereco ler(){

    Endereco cliente;
    printf("Digite seu nome: \n");
    scanf(" %[^\n]",cliente.nome);
    printf("Digite sua rua: \n");
    scanf(" %[^\n]",cliente.rua);
    printf("Digite seu bairro: \n");
    scanf(" %[^\n]",cliente.bairro);
    printf("Digite o numero da casa: \n");
    scanf("%d", &cliente.num);
    cont ++;
    return cliente;
}

int pedir_agua(int ID){
    Endereco vet[cont];
    int numagua = 0;
    printf("Quer quantas águas?\n");
    scanf("%d", &numagua);
    vet[cont] = ler();
    printf("****\n");
    printf("NOME: %s RUA: %s BAIRRO: %s NUMERO: %d QUANTIDA DE AGUA: %d\n", vet[ID].nome, vet[ID].rua, vet[ID].bairro, vet[ID].num, numagua);
    FILE *arq = fopen("data_agua.txt", "w");
       fprintf(arq, "CODIGO DO CLIENTE %d\n", ID);
       fprintf(arq, "NOME: %s\nRUA: %s\nBAIRRO: %s\nNUMERO: %d\nQUANTIDADE DE AGUA: %d\n", vet[ID].nome,vet[ID].rua, vet[ID].bairro, vet[ID].num, numagua);
       if(arq == NULL){
           printf("Arquivo não encontrado.");
       }

       fclose(arq);

    return numagua;
}
