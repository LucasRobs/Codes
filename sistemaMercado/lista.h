void carregar_materiais(Construcao construcoes[], int *construcoes_size){
    char * arquivo = "lista.txt";
    FILE * arq = fopen(arquivo, "r");
    if(arq == NULL){
        return;
    }
    int size = 0;
    fscanf(arq, "%d", &size);
    *construcoes_size = size;
    for(int i = 0; i < size; i++){
        fscanf(arq, "%s", construcoes[i].produto);
        fscanf(arq, "%f", &construcoes[i].valor);
    } 
}

void salvar_materiais(Construcao construcoes[], int *construcoes_size){
    char * arquivo = "lista.txt";
    FILE * arq = fopen(arquivo, "w");
    fprintf(arq, "%d\n", *construcoes_size);
    for(int i = 0; i < *construcoes_size; i++){
        fprintf(arq, "%s ", construcoes[i].produto);
        fprintf(arq, "%.2f\n", construcoes[i].valor);
    }
}