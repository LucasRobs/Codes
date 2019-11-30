#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome  [50];
    char email [50];
    char cpf [11];
} Pessoa;

void menu (Pessoa *vetor, int tamanho);
Pessoa * cadastrar (Pessoa *vetor, int *tamanho);
Pessoa * remover (Pessoa *vetor, int *tamanho);
//void pesquisar (Pessoa *vetor, int *tamanho);
void listar (Pessoa *vetor, int tamanho);

int main (int argc, char const *argv[]){
    Pessoa *pessoas;
    int n = 0;
    menu(pessoas, n);
    return 0;
}

void menu(Pessoa *vetor, int tamanho){
    int operacao;
    do{
        system ("clear");
        printf ("\n    CADASTRO DE PESSOAS   \n__________\n1 - CADASTRAR \n2 - REMOVER \n3 - PESQUISAR \n4 - LISTAR TODOS\n5 - SAIR\n__________");
        printf ("\n");
        printf ("INSIRA A OPÇÃO DESEJADA\n\n");
        scanf ("%d", &operacao);
        getchar();
        switch (operacao){
                case 1:
                    vetor = cadastrar(vetor, &tamanho);
                    break;
                case 2:
                    vetor = remover(vetor, &tamanho);
                    break;
                case 3:
                    //pesquisar(vetor, &tamanho);
                    break;
                case 4:
                    listar(vetor, tamanho);
                    break;
                case 5:
                    return;
        }
    }while (operacao != 0);
}

Pessoa * cadastrar (Pessoa *vetor, int *tamanho){
    system ("clear");
    int op;
    do{
        Pessoa pessoa;
        //Variável que verifica se o cadastro vai poder ser efetuado
        int verificaCadastro = 1;
        printf ("\nInforme seu Nome: ");
        scanf("%[^\n]", pessoa.nome);
        getchar();
        printf ("\nInforme seu Email: ");
        scanf("%[^\n]", pessoa.email);
        getchar();
        printf ("\nInforme seu Cpf: ");
        scanf("%[^\n]", pessoa.cpf);

        if(*tamanho > 0){
            //Realoca o vetor com mais uma posição
            vetor = (Pessoa*) realloc(vetor, ((*tamanho) + 1) * sizeof(Pessoa));
            //Verifica se o vetor foi alocado corretamente
            if(vetor == NULL){
                printf("Não foi possível realizar o cadastro, erro de alocação.");
                verificaCadastro = 0;
            }
        }else{
            //Aloca o vetor
            vetor = (Pessoa*) malloc(((*tamanho) + 1) * sizeof(Pessoa));
            if(vetor == NULL){
                printf("Não foi possível realizar o cadastro, erro de alocação.");
                verificaCadastro = 0;
            }
        }

        //Se a alocação não tiver dado problema insere a pessoa na nova posição a incrementa o tamanho do vetor
        if(verificaCadastro){
            vetor[*tamanho] = pessoa;
            (*tamanho)++;
        }

        printf ("\n1 - CONTINUAR\n0 - SAIR\n");
        scanf ("%d",&op);
        getchar();
    }while (op != 0);

    return vetor;
}

Pessoa * remover (Pessoa *vetor, int *tamanho){
    int id;
    listar(vetor, *tamanho);
    printf ("\nDigite o Id da pessoa que deseja remover: ");
    scanf("%d",&id);
    --id;

    //Verifica se a pessoa a ser removida não está na última posição do vetor
    if(id != (*tamanho) - 1)
        vetor[(*tamanho) - 1] = vetor[id];
    printf("Removido");
    vetor = (Pessoa*) realloc(vetor, ((*tamanho) - 1) * sizeof(Pessoa));
    (*tamanho)--;

    printf("\n Pessoa excluída com sucesso!!!\n");

    return vetor;
}

void pesquisar(Pessoa *vetor, int *tamanho){
     int op;
     char cpfPesquisa;
     char emailPesquisa[50];
     do{
         printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar por email: \n");
         scanf("%d", &op);
         switch(op){
             case 1:
                 printf("\nDigite o CPF: ");
                 scanf("%s", &cpfPesquisa);
                 for(int i=0; i<*tamanho;i++){
                     if(strcmp(vetor[i].cpf == cpfPesquisa)){
                         printf("\nNome:%s\nEmail:%s\nCPF:%s", vetor[i].nome, vetor[i].email, vetor[i].cpf);
                     }
                 }
                 break;
             case 2:
                 printf("\nDigite o E-mail: ");
                 scanf("%s", emailPesquisa);
                 for(int i=0;i<*tamanho;i++){
                     if(strcmp(pessoas[i].email, emailPesquisa)){
                         printf("\nNome:%s\nEmail:%s\nCPF:%s", vetor[i].nome, vetor[i].email, vetor[i].cpf);
                     }
                 }
                 break;
             default:
                 printf("\n Opção invalida");
                 break;
         }
         printf("\nDigite 1 para continuar pesquisando ");
         scanf("%d", &op);    
     }while(op==1);
 }

void listar(Pessoa *vetor, int tamanho){
    system ("clear");
    printf("\nLISTA DE PESSOAS\n");
    for (int i = 0; i < tamanho; i++){
        printf ("\n -------------------------\n");
        printf("%s\n", vetor[i].nome);
        printf("%s\n", vetor[i].email);
        printf("%s", vetor[i].cpf);
        printf ("\n -------------------------\n");
    }
    getchar();
}