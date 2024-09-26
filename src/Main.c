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

int main(){
   
    int opcao;
    

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

                break;
            case 2:
            
                break;
            case 3:
      
                break;
            case 4:
   
                break;
            case 5:
                system("clear");
                break;
            case 6:
                exit(0);
        }
    }

    return 0;
}