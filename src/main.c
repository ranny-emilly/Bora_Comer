#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// outros módulos
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
        printf("Escolha uma opcaoo: ");
        
        // Validação básica de entrada para garantir que o usuário digite um número
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite um numero valido!\n");
            while(getchar() != '\n'); // Limpa o buffer do teclado
            continue;
        }

        switch(opcao) {
            case 1:
                //menu do módulo de funcionários
                menuFuncionarios();
                break;
            case 2:
                //menu do módulo de cardápio
                menuCardapio();
                break;
            case 3:
                //menu do módulo de fila de espera
                //endereço da fila para que as alterações sejam mantidas
                // Nota: Pode ser necessário ajustar a assinatura de menuFila no fila.h
                // se quiser passar a fila como parâmetro, ou mantê-la global/estática lá.
                // Por enquanto, chamamos a função do menu.
                menuFila();
                break;
            case 4:
                // Chama o menu do módulo de pedidos
                // Passamos o endereço da pilha para que as alterações sejam mantidas
                // Nota: Similar à fila, verifique se menuPedidos precisa receber a pilha.
                menuPedidos();
                break;
            case 0:
                printf("\nSaindo do sistema... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
        // Pausa antes de limpar a tela ou mostrar o menu novamente
        printf("\nPressione Enter para continuar...");
        while(getchar() != '\n');  
            getchar();    

    } while (opcao != 0);

    return 0;
}