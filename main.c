#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Incluindo os cabeçalhos dos outros módulos
#include "funcionarios.h"
#include "cardapio.h"
#include "pedidos.h"
#include "fila.h"

// Função utilitária para limpar a tela (funciona em Windows e Linux/Mac)
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

    // TODO: Inicializar estruturas globais aqui (ex: filas, pilhas)
    // Ex: Pedido* pilhaPedidos = NULL;
    // Ex: Cliente* filaEspera = NULL;

    do {
        // limparTela(); // Descomente para limpar a tela a cada loop
        printf("\n=== BORA COMER - SISTEMA DE RESTAURANTE ===\n");
        printf("1. Gestão de Funcionários (Gabs)\n");
        printf("2. Gestão do Cardápio (Jolie)\n");
        printf("3. Fila de Espera (Emilly)\n");
        printf("4. Pedidos e Cozinha (Elisa)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        
        // Validação básica de entrada (para não quebrar com letras)
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite um número válido!\n");
            while(getchar() != '\n'); // Limpa o buffer do teclado
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
                printf("\nSaindo do sistema... Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar(); getchar(); // Pausa para o usuário ler
        }

    } while (opcao != 0);

    return 0;
}
