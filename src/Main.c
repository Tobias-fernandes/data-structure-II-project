#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura de uma fruta
typedef struct Fruta {
    char nome[50];
    int quantidade;
    float preco;
} Fruta;

//Estrutura de um nó
typedef struct No {
    Fruta fruta;
    struct No *esquerda;
    struct No *direita;
} No;

//Função para criar um nó
No *criarNo(Fruta fruta) {
    No *novo = (No *) malloc(sizeof(No));
    novo->fruta = fruta;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

//Função para inserir um nó na arvore
void inserir(No **raiz, Fruta fruta) {
    //Se a raiz for nula, o nó é inserido na raiz
    if (*raiz == NULL) {
        *raiz = criarNo(fruta);
    } 
    //Verificando se a fruta já existe na arvore
    else if (strcmp(fruta.nome, (*raiz)->fruta.nome) == 0) {
        (*raiz)->fruta = fruta;
    }

    //Se o nome da fruta for menor que o nome da raiz, a função é chamada recursivamente para a esquerda
    else if (strcmp(fruta.nome, (*raiz)->fruta.nome) < 0) {
        inserir(&(*raiz)->esquerda, fruta);
    }
    //Se o nome da fruta for maior que o nome da raiz, a função é chamada recursivamente para a direita
    else {
        inserir(&(*raiz)->direita, fruta);
    }
}

//Função para imprimir a arvore
void imprimir(No *raiz) {
    //Se a raiz for nula, a função é encerrada
    if (raiz != NULL) {
        printf("FRUTAS\n\n");
        imprimir(raiz->esquerda);
        printf("Nome: %s\n", raiz->fruta.nome);
        printf("Quantidade: %d\n", raiz->fruta.quantidade);
        printf("Preco: %.2f\n\n", raiz->fruta.preco);
        printf("\n");
        imprimir(raiz->direita);
    }
}

//Função para buscar um nó na arvore
int buscar(No *raiz, char nome[]) {
    //Se a raiz for nula, a função é encerrada
    if (raiz == NULL) {
        return 0;
    } 
    //Se o nome da fruta for igual ao nome da raiz, a função retorna 1
    else {
        //Se o nome da fruta for menor que o nome da raiz, a função é chamada recursivamente para a esquerda
        if (strcmp(nome, raiz->fruta.nome) == 0) {
            return 1;
        }
        //Se o nome da fruta for menor que o nome da raiz, a função é chamada recursivamente para a esquerda
        else if (strcmp(nome, raiz->fruta.nome) < 0) {
            return buscar(raiz->esquerda, nome);
        } 
        //Se o nome da fruta for maior que o nome da raiz, a função é chamada recursivamente para a direita
        else {
            return buscar(raiz->direita, nome);
        }
    }
}

//função para remover um nó da arvore
No *remover(No *raiz, char nome[]) {
    //Se a raiz for nula, a função é encerrada
    if (raiz == NULL) {
        return raiz;
    }
    //Se o nome da fruta for menor que o nome da raiz, a função é chamada recursivamente para a esquerda
    if (strcmp(nome, raiz->fruta.nome) < 0) {
        raiz->esquerda = remover(raiz->esquerda, nome);
    } 
    //Se o nome da fruta for maior que o nome da raiz, a função é chamada recursivamente para a direita
    else if (strcmp(nome, raiz->fruta.nome) > 0) {
        raiz->direita = remover(raiz->direita, nome);
    } 
    //Se o nome da fruta for igual ao nome da raiz, o nó é removido
    else {
        //Se a raiz não tiver filhos, a raiz é liberada
        if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        } 
        //Se a raiz não tiver filhos, a raiz é liberada
        else if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        //Se a raiz tiver dois filhos, o nó é substituido pelo nó mais a esquerda da subarvore direita
        No *temp = raiz->direita;
        //Encontra o nó mais a esquerda da subarvore direita
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        //Copia o nó mais a esquerda da subarvore direita para a raiz
        strcpy(raiz->fruta.nome, temp->fruta.nome);
        raiz->direita = remover(raiz->direita, temp->fruta.nome);
    }
    //Retorna a raiz
    return raiz;
}

//função para modificar um nó da arvore
void modificar(No *raiz, char nome[], Fruta fruta) {
    //Se a raiz for nula, a função é encerrada
    if (raiz == NULL) {
        return;
    }
    //Se o nome da fruta for menor que o nome da raiz, a função é chamada recursivamente para a esquerda
    if (strcmp(nome, raiz->fruta.nome) < 0) {
        modificar(raiz->esquerda, nome, fruta);
    } 
    //Se o nome da fruta for maior que o nome da raiz, a função é chamada recursivamente para a direita
    else if (strcmp(nome, raiz->fruta.nome) > 0) {
        modificar(raiz->direita, nome, fruta);
    } 
    //Se o nome da fruta for igual ao nome da raiz, a fruta é modificada
    else {
        raiz->fruta = fruta;
    }
}

int main() {
    No *raiz = NULL;
    Fruta fruta;
    int opcao;
    char nome[50];

    while (1) {
        printf("1. Inserir fruta\n");
        printf("2. Remover fruta\n");
        printf("3. Buscar fruta\n");
        printf("4. Modificar fruta\n");
        printf("5. Imprimir\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("clear");
                printf("Nome: ");
                scanf("%s", fruta.nome);
                printf("Quantidade: ");
                scanf("%d", &fruta.quantidade);
                printf("Preco: ");
                scanf("%f", &fruta.preco);
                inserir(&raiz, fruta);
                system("clear");
                printf("Fruta Adicionada com sucesso!\n");
                break;
            case 2:
                system("clear");
                printf("Nome: ");
                scanf("%s", nome);
                raiz = remover(raiz, nome);
                system("clear");
                //informando se a fruta foi removida ou não
                if (raiz == NULL) {
                    printf("Fruta removida com sucesso!!\n");
                } else
                {
                    printf("Fruta nao encontrada\n");
                }
                
                break;
            case 3:
                system("clear");
                printf("Nome: ");
                scanf("%s", nome);
                if (buscar(raiz, nome)) {
                    system("clear");
                    printf("Fruta encontrada\n");
                    printf("Nome: %s\n", raiz->fruta.nome);
                    printf("Quantidade: %d\n", raiz->fruta.quantidade);
                    printf("Preco: %.2f\n", raiz->fruta.preco);
                } else {
                    printf("Fruta nao encontrada\n");
                }
                break;
            case 4:
                system("clear");
                printf("Nome: ");
                scanf("%s", nome);
                printf("Nome: ");
                scanf("%s", fruta.nome);
                printf("Quantidade: ");
                scanf("%d", &fruta.quantidade);
                printf("Preco: ");
                scanf("%f", &fruta.preco);
                modificar(raiz, nome, fruta);
                system("clear");
                printf("Fruta modificada com sucesso!!\n");
                printf("Novos dados da fruta:\n");
                printf("Nome: %s\n", fruta.nome);
                printf("Quantidade: %d\n", fruta.quantidade);
                printf("Preco: %.2f\n", fruta.preco);
                break;
            case 5:
                system("clear");
                imprimir(raiz);
                break;
            case 6:
                exit(0);
        }
    }

    return 0;
}

//Meta desse projeto: criar um menu para uma barraca de frutas usando arvores binarias
// 1. Inserir fruta
// 2. Remover fruta
// 3. Buscar fruta
// 4. Modiicar fruta
