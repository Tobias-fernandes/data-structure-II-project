#include <stdio.h>
#include "funcoes.c"
int main() {
    //Adicionando variaves necessarias
    Vendedores *raiz = NULL;
    Frutas frutas[50];
    char nome[50], cpf[15], nomeFruta[50];
    int quantidade;
    float preco;

    //Adicionando o menu 
    menu();
    char opcao[1];
    system("clear");

    //Criando um loop para o menu
    while(opcao != "0"){
        menu();
        printf("Digite a opção desejada: ");
        scanf("%s", opcao);
        system("clear");

        //Adicionando as 11 opções do menu do arquivo funcoes.c
        switch (opcao[0]){
           
            case '1':
                printf("Digite o cpf do novo vendedor: \n");
                scanf(" %[^\n]", cpf);
                
                //verificando se o cpf é um número
                for(int i = 0; i < 11; i++){
                    if(cpf[i] < '0' || cpf[i] > '9'){
                        printf("CPF inválido, digite apenas numeros.\n");
                        break;
                    }
                }
                
                //verificando se o cpf é valido
                if(strlen(cpf) != 11){
                    printf("CPF inválido, o cpf precisa ter 11 numeros.\n");
                    break;
                }
                
                //verificando se o cpf já existe
                if(buscarVendedor(raiz, cpf) != NULL){
                    printf("CPF já existe\n");
                    break;
                }
                
                printf("Digite o nome do novo vendedor: \n");
                scanf(" %[^\n]", nome);
                //verificando se existe numeros e caracteres especiais no nome
                for(int i = 0; i < strlen(nome); i++){
                    if(isdigit(nome[i]) || ispunct(nome[i])){
                        printf("Nome inválido, digite apenas letras.\n");
                        break;
                    }
                }

                raiz = inserirVendedor(raiz, nome, cpf);
                printf("Vendedor adicionado com sucesso\n");

                break;
            case '2':
               
                printf("Digite o cpf do vendedor: \n");
                scanf(" %[^\n]", cpf);
                raiz = removerVendedor(raiz, cpf);
                
                break;
            case '3':
               
                printf("Digite o cpf do vendedor: \n");
                scanf(" %[^\n]", cpf);
                
                Vendedores *vendedor = buscarVendedor(raiz, cpf);
                
                if(vendedor != NULL){
                    printf("Nome: %s\n", vendedor->nome);
                    printf("CPF: %s\n", vendedor->cpf);
                    for(int i = 0; i < 50; i++){
                        if(vendedor->frutas[i].quantidade != 0){
                            printf("Fruta: %s\n", vendedor->frutas[i].nome);
                            printf("Quantidade: %d\n", vendedor->frutas[i].quantidade);
                            printf("Preço: %.2f\n", vendedor->frutas[i].preco);
                        }
                    }
                }
                
                else{
                    printf("Vendedor não encontrado\n");
                }
                
                break;
            case '4':
                
                printf("Digite o cpf do vendedor: \n");
                scanf(" %[^\n]", cpf);
               
                //verificando se o vendedor existe
                if(buscarVendedor(raiz, cpf) == NULL){
                    printf("Vendedor não encontrado\n");
                    break;
                }
                
                raiz = modificarVendedor(raiz, cpf);
                
                break;
            case '5':
                
                printf("Digite o cpf do vendedor aonde deseja adicionar a fruta: \n");
                scanf(" %[^\n]", cpf);
                printf("Digite o nome da fruta: \n");
                scanf(" %[^\n]", nomeFruta);
               
                //verificando se no nome da fruta existe números
                for(int i = 0; i < strlen(nomeFruta); i++){
                    if(isdigit(nomeFruta[i])){
                        printf("Nome inválido\n");
                        break;
                    }
                }
                
                //verificando se o vendedor já tem a fruta
                if(buscarFruta(raiz, cpf, nomeFruta) != NULL){
                    printf("Fruta já existe\n");
                    break;
                }

                printf("Digite a quantidade da fruta: \n");
                scanf("%d", &quantidade);

                //verificando se a quantidade é um número
                if(quantidade < 0){
                    printf("Quantidade inválida\n");
                    break;
                }

                printf("Digite o preço da fruta: \n");
                scanf("%f", &preco);

                //verificando se o preço é um número
                if(preco < 0){
                    printf("Preço inválido\n");
                    break;
                }

                raiz = adicionarFruta(raiz, cpf, nomeFruta, quantidade, preco);
                printf("Fruta adicionada com sucesso\n");
                break;
            case '6':
                
                printf("Digite o cpf do vendedor aonde deseja remover a fruta: \n");
                scanf(" %[^\n]", cpf);
                printf("Digite o nome da fruta: \n");
                scanf(" %[^\n]", nomeFruta);
                
                raiz = removerFruta(raiz, cpf, nomeFruta);
                printf("Fruta removida com sucesso\n");
                
                break;

            case '7':
                
                printf("Digite o cpf do vendedor aonde deseja buscar a fruta: \n");
                scanf(" %[^\n]", cpf);
                printf("Digite o nome da fruta: \n");
                scanf(" %[^\n]", nomeFruta);
               
                Frutas *frutaBuscada = buscarFruta(raiz, cpf, nomeFruta);
                
                if(frutaBuscada != NULL){
                    printf("Fruta encontrada\n");
                    printf("Nome: %s\n", frutaBuscada->nome);
                    printf("Quantidade: %d\n", frutaBuscada->quantidade);
                    printf("Preço: %.2f\n", frutaBuscada->preco);
                }
                
                else{
                    printf("Fruta não encontrada\n");
                }
               
                break;

            case '8':
                
                printf("Digite o cpf do vendedor aonde deseja modificar a fruta: \n");
                scanf(" %[^\n]", cpf);
                
                //verificando se o vendedor existe
                if(buscarVendedor(raiz, cpf) == NULL){
                    printf("Vendedor não encontrado\n");
                    break;
                }
                
                printf("Digite o nome da fruta que deseja modificar: \n");
                scanf(" %[^\n]", nomeFruta);
                
                //verificando se a fruta existe
                if(buscarFruta(raiz, cpf, nomeFruta) == NULL){
                    printf("Fruta não encontrada\n");
                    break;
                }
                
                //se exitsir a fruta, o programa ira modificar a fruta
                printf("Digite o novo nome da fruta: \n");
                scanf(" %[^\n]", nomeFruta);
                
                //verificando se o novo nome da fruta já existe no estoque
                if(buscarFruta(raiz, cpf, nomeFruta) != NULL){
                    printf("Fruta já existe no estoque\n");
                    break;
                }      
                
                printf("Digite a nova quantidade da fruta: \n");
                scanf("%d", &quantidade);
                printf("Digite o novo preço da fruta: \n");
                scanf("%f", &preco);
                
                raiz = modificarFruta(raiz, cpf, nomeFruta, quantidade, preco);
                
                break;
            
            case '0':
                
                printf("Saindo do programa\n");
                liberarMemoria(raiz);
                exit(0);
                break;
        
        }
    }
    return 0;
}

//Meta desse projeto: criar um menu para uma barraca de frutas usando arvores binarias
// 1. Inserir fruta
// 2. Remover fruta
// 3. Buscar fruta
// 4. Modiicar fruta

//Tratativas que precisam ser feitas:
// 1. verificação de números em lugares que não pedem números
// 2. verificação de letras em lugares que não pedem letras 
// 3. Deixar todos os caracteres em letras minusculas
// 4. Verificação de frutas repetidas
// 5. Verificação de frutas que não existem

//Algumas das tecnoogias que serão usadas:
// 1. Arvores binarias
// 2. Tabela hash 
// 3. heap