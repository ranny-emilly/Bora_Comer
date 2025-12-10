#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#include "funcionarios.h"
#include "cardapio.h"
#include "pedidos.h"
#include "fila.h"


void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    
    Pedido* pilhaPedidos = NULL;
    Cliente* filaEspera = NULL;

    do {
        limparTela();
        printf("\n=== BORA COMER - SISTEMA DE RESTAURANTE ===\n");
        printf("1. Gestao de Funcionarios \n");
        printf("2. Gestao do Cardapio \n");
        printf("3. Fila de Espera \n");
        printf("4. Pedidos e Cozinha \n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite um numero valido!\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch(opcao) {
            case 1:
                
                menuFuncionarios();
                break;
            case 2:
               
                menuCardapio();
                break;
            case 3:
               
                menuFila();
                break;
            case 4:
                
                menuPedidos();
                break;
            case 0:
                printf("\nSaindo do sistema... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
       
        printf("\nPressione Enter para continuar...");
        while(getchar() != '\n');  
            getchar();    

    } while (opcao != 0);

    return 0;
}
