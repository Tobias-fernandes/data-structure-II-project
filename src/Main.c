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


int main(){
    return 0;
}