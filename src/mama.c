
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string é um palíndromo
int isPalindrome(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        // Ignorar espaços e caracteres não alfabéticos
        if (!isalnum(str[inicio])) {
            inicio++;
        } else if (!isalnum(str[fim])) {
            fim--;
        } else {
            // Comparar os caracteres ignorando maiúsculas/minúsculas
            if (tolower(str[inicio]) != tolower(str[fim])) {
                return 0; // Não é um palíndromo
            }
            inicio++;
            fim--;
        }
    }

    return 1; // É um palíndromo
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o '\n' da string
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("A string é um palíndromo.\n");
    } else {
        printf("A string não é um palíndromo.\n");
    }

    return 0;
}