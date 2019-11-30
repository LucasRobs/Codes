#include <stdbool.h>
#include <unistd.h>
#define SENHA 1234

typedef struct{
    char nome[50];
    float preco;
    int quantidade;
    int id;
}Produto;

Produto * lerBanco(int *tamanho){
    Produto *vetor;
    vetor = (Produto*) malloc(sizeof(Produto));
    FILE * arquivo;
    arquivo = fopen("banco.txt","r");
    if(arquivo == NULL){
        puts("TURURU FALHA!");
    }else{
        int x = 0;
        while(!feof(arquivo)){
            fgets(vetor[x].nome,50,arquivo);
            vetor[x].nome[strlen(vetor[x].nome) - 1] = 0; //corretor do banco
            fscanf(arquivo, "%f", &vetor[x].preco);
            fscanf(arquivo, "%d", &vetor[x].quantidade);
            char lixo = getc(arquivo); //limpar buffer
            vetor[x].id = x;
            x += 1;
            if(!feof(arquivo)){
                vetor = (Produto*) realloc(vetor, (x + 1) * sizeof(Produto));
            }
        }
        *tamanho = x;
    }
    fclose(arquivo);
    return vetor;
}

void escreverBanco(Produto * vetor, int tamanho){
    FILE * arquivo;
    arquivo = fopen("banco.txt","w");
    if(arquivo == NULL){
        puts("TURURU FALHA!");
    }else{
        for(int i = 0; i < tamanho; i++){
            fprintf(arquivo, "%s\n", vetor[i].nome);
            fprintf(arquivo, "%f\n", vetor[i].preco);
            fprintf(arquivo, "%d", vetor[i].quantidade);
            if(i != tamanho -1){
                fprintf(arquivo, "\n");
            }
        }
    }
    fclose(arquivo);
    puts("Carregando banco de dados!");
    sleep(1);
}

bool login(){
    int senha = 0;
    puts("DIGITE A SENHA");
    scanf("%d", &senha);
    if(senha == SENHA){
        return true;
    }else{
        printf("senha incorreta");
        return false;
    }
}

Produto * cadastrar (Produto *vetor, int *tamanho){
    int op;
    do{
        Produto produto;
        //Variável que verifica se o cadastro vai poder ser efetuado
        int verificaCadastro = 1;
        printf ("\nNome: ");
        scanf("%[^\n]", produto.nome);
        printf ("\nPreco: ");
        scanf("%f", &produto.preco);
        printf ("\nQuantidade: ");
        scanf("%d", &produto.quantidade);
        produto.id = *tamanho;
            
        if(*tamanho > 0){
            //Realoca o vetor com mais uma posição
            vetor = (Produto*) realloc(vetor, ((*tamanho) + 1) * sizeof(Produto));
            //Verifica se o vetor foi alocado corretamente
            if(vetor == NULL){
                verificaCadastro = 0;
            }
        }else{
            //Aloca o vetor
            vetor = (Produto*) malloc(((*tamanho) + 1) * sizeof(Produto));
            
            if(vetor == NULL){
                printf("Não foi possível realizar o cadastro, erro de alocação.");
                verificaCadastro = 1;
            }
        }

        //insere a produto na nova posição a incrementa o tamanho do vetor
        if(verificaCadastro){
            vetor[*tamanho] = produto;
            (*tamanho)++;
        }

        printf ("\n1 - CONTINUAR\n0 - SAIR\n");
        scanf ("%d",&op);
        getchar();
    }while (op != 0);
    return vetor;
}
void listar(Produto *vetor, int tamanho){
    printf(" LISTA DE Produtos\n");
    printf ("\n -------------------------\n");
    for(int i = 0; i < tamanho; i++){
        printf("Nome  : %s\n", vetor[i].nome);
        printf("Preço : %.2f\n", vetor[i].preco);
        printf("Qtd   : %d\n", vetor[i].quantidade);
        printf("ID    : %d", vetor[i].id);
        printf ("\n -------------------------\n");
    }
    getchar();
}

Produto * remover(Produto *vetor, int *tamanho){
    int id;
    listar(vetor, *tamanho);
    printf ("\nDigite o Id do produto que deseja remover: ");
    scanf("%d",&id);
    for(int i = id; i < *tamanho-1; i++){
        vetor[i] = vetor[i+1];
    }
    vetor = (Produto*) realloc(vetor, ((*tamanho) - 1) * sizeof(Produto));
    (*tamanho)--;

    printf("\n Produto excluido com sucesso !!!\n");
    return vetor;
    getchar();
}
void pesquisar(Produto *vetor, int *tamanho){
    int op = 0;
    char nomePesquisa[50];
    int id = 0;
    do{
        printf("\nDigite 1 para pesquisar por nome ou 2 para pesquisar por ID: \n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nDigite o nome: ");
                scanf("%s", nomePesquisa);
                for(int i = 0; i<*tamanho; i++){
                    for(int t = 0; t < strlen(vetor[i].nome); t++){
                        if(vetor[i].nome[t] == nomePesquisa[t]){
                            if(t == strlen(vetor[i].nome) - 1){
                                printf("Nome  : %s\n", vetor[i].nome);
                                printf("Preço : %.2f\n", vetor[i].preco);
                                printf("Qtd   : %d\n", vetor[i].quantidade);
                                printf("ID    : %d", vetor[i].id);        
                            }
                        }else{
                            break;
                        }
                    }
                }
                break;
            case 2:
                printf("\nDigite o ID: ");
                scanf("%d", &id);
                for(int i=0;i<*tamanho;i++){
                    if(vetor[i].id == id){
                        printf("Nome  : %s\n", vetor[i].nome);
                        printf("Preço : %.2f\n", vetor[i].preco);
                        printf("Qtd   : %d\n", vetor[i].quantidade);
                        printf("ID    : %d", vetor[i].id);
                    }
                }
                break;
            default:
                printf("\n Opção invalida");
                break;
        }
        printf("\nDigite 1 para continuar pesquisando ou 0 para sair");
        scanf("%d", &op);    
    }while(op==1);
}
Produto * Adicionarqtd(Produto *vetor, int *tamanho){
    int id = 0, qtd = 0;
    printf("\nDigite o ID: ");
    scanf("%d", &id);
    for(int i=0;i<*tamanho;i++){
        if(vetor[i].id == id){
            printf("DIGITE A QUANTIDADE QUE DESEJA ADICIONAR: ");
            scanf("%d", &qtd);
            vetor[i].quantidade += qtd;
        }
    }
    return vetor;
}

Produto * menu(Produto *vetor, int *tamanho){
    int operacao = 0;
    do{
        system ("clear");
        printf ("\n    CADASTRO DE Produtos   \n__________\n1 - CADASTRAR \n2 - REMOVER \n3 - PESQUISAR \n4 - LISTAR TODOS \n5 - ADICIONAR QUANTIDADE \n6 - SAIR\n__________");
        printf ("\n");
        printf ("INSIRA A OPÇÃO DESEJADA\n\n");
        scanf ("%d", &operacao);
        getchar();
        switch (operacao){
                case 1:
                    vetor = cadastrar(vetor, tamanho);
                    escreverBanco(vetor, *tamanho);             
                    break;
                case 2:
                    vetor = remover(vetor, tamanho);
                    break;
                case 3:
                    pesquisar(vetor, tamanho);
                    break;
                case 4:
                    listar(vetor, *tamanho);
                    break;

                case 5:
                    vetor = Adicionarqtd(vetor, tamanho);
                    break;
                case 6:
                    system ("clear");
                    return vetor;
                default:
                    printf("DIGITE UM NUMERO ENTRE 1 E 6 !!!"); 
        }
    }while (operacao != 0);
    return NULL;
}

