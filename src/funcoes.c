#include "/home/lailson/Desktop/Projeto kenned/Projeto de kenned/include/funcoes.h"

//Função do menu
void menu(){
    printf("-------------------Barraca de frutas-------------------\n");
    printf("|                                                     |\n");
    printf("| 1 - Adicionar vendedor                              |\n");
    printf("| 2 - Remover vendedor                                |\n");
    printf("| 3 - Buscar vendedor                                 |\n");
    printf("| 4 - Modificar vendedor                              |\n");
    printf("| 5 - Adicionar fruta                                 |\n");
    printf("| 6 - Remover fruta                                   |\n");
    printf("| 7 - Buscar fruta                                    |\n");
    printf("| 8 - Modificar fruta                                 |\n");
    printf("| 9 - Imprimir vendedores e frutas                    |\n");
    printf("| 0 - Sair                                            |\n");
}

//Função que irar criar um vendedor
Vendedores *criarVendedor(char nome[], char cpf[]){
    Vendedores *novo = (Vendedores *)malloc(sizeof(Vendedores));
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//Função que irar inserir um vendedor
Vendedores *inserirVendedor(Vendedores *raiz, char nome[], char cpf[]){
    if(raiz == NULL){
        return criarVendedor(nome, cpf);
    }
    if(strcmp(cpf, raiz->cpf) < 0){
        raiz->esq = inserirVendedor(raiz->esq, nome, cpf);
    }else if(strcmp(cpf, raiz->cpf) > 0){
        raiz->dir = inserirVendedor(raiz->dir, nome, cpf);
    }
    return raiz;
}

//Função que irar remover um vendedor
Vendedores *removerVendedor(Vendedores *raiz, char cpf[]){
    if(raiz == NULL){
        return NULL;
    }
    if(strcmp(cpf, raiz->cpf) < 0){
        raiz->esq = removerVendedor(raiz->esq, cpf);
    }else if(strcmp(cpf, raiz->cpf) > 0){
        raiz->dir = removerVendedor(raiz->dir, cpf);
    }else{
        if(raiz->esq == NULL){
            Vendedores *aux = raiz->dir;
            free(raiz);
            return aux;
        }else if(raiz->dir == NULL){
            Vendedores *aux = raiz->esq;
            free(raiz);
            return aux;
        }else{
            Vendedores *aux = raiz->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
            strcpy(raiz->nome, aux->nome);
            strcpy(raiz->cpf, aux->cpf);
            raiz->esq = removerVendedor(raiz->esq, aux->cpf);
        }
    }
    return raiz;
}

//Função que irar buscar um vendedor com hash
Vendedores *buscarVendedor(Vendedores *raiz, char cpf[]){
    if(raiz == NULL){
        return NULL;
    }
    if(strcmp(cpf, raiz->cpf) < 0){
        return buscarVendedor(raiz->esq, cpf);
    }else if(strcmp(cpf, raiz->cpf) > 0){
        return buscarVendedor(raiz->dir, cpf);
    }
    return raiz;
}

//Função que irar modificar um vendedor
Vendedores *modificarVendedor(Vendedores *raiz, char cpf[]){
    if(raiz == NULL){
        return NULL;
    }
    if(strcmp(cpf, raiz->cpf) < 0){
        raiz->esq = modificarVendedor(raiz->esq, cpf);
    }else if(strcmp(cpf, raiz->cpf) > 0){
        raiz->dir = modificarVendedor(raiz->dir, cpf);
    }else{
        char nome[50];
        printf("Digite o novo nome do vendedor: ");
        scanf(" %[^\n]", nome);
        strcpy(raiz->nome, nome);
    }
    return raiz;
}

//Função que irar adicionar uma fruta
Vendedores *adicionarFruta(Vendedores *raiz, char cpf[], char nome[], int quantidade, float preco){
    Vendedores *vendedor = buscarVendedor(raiz, cpf);
    if(vendedor == NULL){
        return raiz;
    }
    for(int i = 0; i < 50; i++){
        if(vendedor->frutas[i].quantidade == 0){
            strcpy(vendedor->frutas[i].nome, nome);
            vendedor->frutas[i].quantidade = quantidade;
            vendedor->frutas[i].preco = preco;
            break;
        }
    }
    return raiz;
}

//Função que irar remover uma fruta
Vendedores *removerFruta(Vendedores *raiz, char cpf[], char nome[]){
    Vendedores *vendedor = buscarVendedor(raiz, cpf);
    if(vendedor == NULL){
        return raiz;
    }
    for(int i = 0; i < 50; i++){
        if(strcmp(vendedor->frutas[i].nome, nome) == 0){
            strcpy(vendedor->frutas[i].nome, "");
            vendedor->frutas[i].quantidade = 0;
            vendedor->frutas[i].preco = 0;
            break;
        }
    }
    return raiz;
}

//Função que irar buscar uma fruta dentro de um vendedor
Frutas *buscarFruta(Vendedores *raiz, char cpf[], char nome[]){
    Vendedores *vendedor = buscarVendedor(raiz, cpf);
    if(vendedor == NULL){
        return NULL;
    }
    for(int i = 0; i < 50; i++){
        if(strcmp(vendedor->frutas[i].nome, nome) == 0){
            return &vendedor->frutas[i];
        }
    }
    return NULL;
}

//Função que irar modificar uma fruta de um vendedor
Vendedores *modificarFruta(Vendedores *raiz, char cpf[], char nome[], int quantidade, float preco){
    Vendedores *vendedor = buscarVendedor(raiz, cpf);
    if(vendedor == NULL){
        return raiz;
    }
    for(int i = 0; i < 50; i++){
        if(strcmp(vendedor->frutas[i].nome, nome) == 0){
            vendedor->frutas[i].quantidade = quantidade;
            vendedor->frutas[i].preco = preco;
            break;
        }
    }
    return raiz;
}


//Função que irar liberar a memoria alocada
void liberarMemoria(Vendedores *raiz){
    if(raiz == NULL){
        return;
    }
    liberarMemoria(raiz->esq);
    liberarMemoria(raiz->dir);
    free(raiz);
}

// Função que irá imprimir os vendedores e suas respectivas frutas
void imprimirVendedoresEFrutas(Vendedores *raiz) {
    if (raiz == NULL) {
        return;
    }
    // Limpa a tela antes de imprimir
    system("clear"); // Use "clear" se estiver no Linux ou macOS

    imprimirVendedoresEFrutas(raiz->esq);

    printf("Nome: %s\n", raiz->nome);
    printf("CPF: %s\n", raiz->cpf);

    // Imprime as frutas associadas ao vendedor
    printf("Frutas do vendedor:\n");
    for (int i = 0; i < 50; i++) {
        if (strlen(raiz->frutas[i].nome) > 0 && raiz->frutas[i].quantidade > 0) {
            printf("\tNome: %s\n", raiz->frutas[i].nome);
            printf("\tQuantidade: %d\n", raiz->frutas[i].quantidade);
            printf("\tPreço: %.2f\n", raiz->frutas[i].preco);
        }
    }
    printf("------------------------\n");

    imprimirVendedoresEFrutas(raiz->dir);
}