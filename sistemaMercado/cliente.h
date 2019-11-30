
/*case 2 : Adicionar produto da lista ao carro
e no momento que adiciona já calcula a soma do valor*/

Produto * adicionarcar(Produto * carrinho,int * tamCar,Produto *vetor, int * tamanho){
    listar(vetor, *tamanho);
    printf("\nDigite o ID: ");
    int id = 0, qtd = 0;
    scanf("%d", &id);
    printf("\nDigite a quantidade: ");
    scanf("%d", &qtd);
    for(int i=0;i<*tamanho;i++){
        if(vetor[i].id == id){
            if(vetor[i].quantidade >= qtd){
                int verificaCadastro = 1;
                if(*tamCar > 1){
                    //realocar vetor com mais uma posição
                    carrinho = (Produto*) realloc(carrinho, ((*tamCar) + 1) * sizeof(Produto));
                    //Verifica se o vetor foi alocado corretamente
                    if(carrinho == NULL){
                        verificaCadastro = 0;
                    }
                }else{
                    //Aloca o vetor
                    carrinho = (Produto*) malloc(((*tamCar) + 1) * sizeof(Produto));
                    if(vetor == NULL){
                        printf("Não foi possível realizar o cadastro, erro de alocação.");
                        verificaCadastro = 0;
                    }
                }
                if(verificaCadastro){
                    vetor[i].quantidade -= qtd;
                    carrinho[*tamCar] = vetor[i];
                    carrinho[*tamCar].quantidade = qtd;
                    *tamCar += 1;
                }
            }else{
                puts("Quantidade insuficiente no estoque. Fale com o gerente!");
                sleep(1);
            }
        }
    }
    return carrinho;
}
//case 3 : Remover produto do carro
Produto * removerCarrinho(Produto * carrinho,int * tamCar,Produto * vetor, int * tamanho){
    listar(carrinho, *tamCar);
    int id = 0;
    printf("\nDigite o ID: ");
    scanf("%d", &id);
    for(int i=0; i<*tamCar; i++){
        if(carrinho[i].id == id){
            vetor[id].quantidade += carrinho[i].quantidade;
            for(int i = id; i < *tamCar-1; i++){
                carrinho[i] = carrinho[i+1];
            }
            carrinho = (Produto*) realloc(carrinho, ((*tamanho) - 1) * sizeof(Produto));
            (*tamCar)--;
            printf("\n Produto excluido com sucesso !!!\n");
        }
    }
    return carrinho;
}
float calcular(Produto * carrinho,int tamCar){
    float total = 0;
    for(int i = 0; i < tamCar; i++){
        total += (carrinho[i].quantidade * carrinho[i].preco);
    }
    return total;
}
Produto * menucliente(Produto *vetor, int *tamanho){
    int operacao = 0, tamCar = 0;
    Produto * carrinho;
    do{
        float total = calcular(carrinho, tamCar);
        system ("clear");
        printf ("\n    CARRINHO  \n__________\n1 - LISTAR TODOS \n2 - PESQUISAR \n3 - ADICIONAR \n4 - REMOVER \n5 - FINALIZAR COMPRA. Total : %.2f\n__________", total );
        printf ("\n");
        printf ("INSIRA A OPÇÃO DESEJADA\n\n");
        scanf ("%d", &operacao);
        getchar();
        switch (operacao){
                case 1:
                    system("clear");
                    printf("Loja > ");
                    listar(vetor, *tamanho);
                    getchar();
                    printf("Carrinho > ");
                    listar(carrinho, tamCar);
                    calcular(carrinho, tamCar);
                    printf("Total : %.2f", total);
                    getchar();
                    break;
                case 2:
                    pesquisar(vetor, tamanho);
                    break;
                case 3:
                    carrinho = adicionarcar(carrinho, &tamCar, vetor, tamanho);
                    break;            
                case 4:
                    carrinho = removerCarrinho(carrinho, &tamCar,vetor, tamanho);
                    break;
                case 5:
                    system ("clear");
                    return vetor;
                default:
                    printf("DIGITE UM NUMERO ENTRE 1 E 5!!!");
        }
    }while(1);
}
