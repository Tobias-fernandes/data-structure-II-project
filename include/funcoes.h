#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Função que irar mostrar o menu;
void menu();

//criando uma estrutura para armazenar os dados das frutas
typedef struct frutas{
    char nome[50];
    int quantidade;
    float preco;
}Frutas;

//Criando uma estrutura para armazenar os dados dos vendedores
typedef struct vendedores{
    char nome[50];
    char cpf[15];
    Frutas frutas[50];
    struct vendedores *esq;
    struct vendedores *dir;
}Vendedores;

//Função que irar criar um vendedor
Vendedores *criarVendedor(char nome[], char cpf[]);

//Função que irar inserir um vendedor
Vendedores *inserirVendedor(Vendedores *raiz, char nome[], char cpf[]);

//Função que irar remover um vendedor
Vendedores *removerVendedor(Vendedores *raiz, char cpf[]);

//Função que irar buscar um vendedor com hash
Vendedores *buscarVendedor(Vendedores *raiz, char cpf[]);

//Função que irar modificar um vendedor
Vendedores *modificarVendedor(Vendedores *raiz, char cpf[]);

//Função que irar adicionar uma fruta
Vendedores *adicionarFruta(Vendedores *raiz, char cpf[], char nome[], int quantidade, float preco);

//Função que irar remover uma fruta
Vendedores *removerFruta(Vendedores *raiz, char cpf[], char nome[]);

//Função que irar buscar uma fruta
Frutas *buscarFruta(Vendedores *raiz, char cpf[], char nome[]);

//Função que irar modificar uma fruta
Vendedores *modificarFruta(Vendedores *raiz, char cpf[], char nome[], int quantidade, float preco);

//Função que irar liberar a memoria alocada
void liberarMemoria(Vendedores *raiz);

//Função que irar imprimir os vendedores e suas frutas
void imprimirVendedoresEFrutas(Vendedores *raiz);
