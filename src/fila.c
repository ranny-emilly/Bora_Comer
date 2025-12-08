#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Variáveis globais/estáticas para controlar o início e o fim da fila DENTRO deste módulo.
// Isso evita ter que passar os ponteiros o tempo todo no main.
static Cliente* inicioFila = NULL;
static Cliente* fimFila = NULL;

void menuFila() {
    int opcao;
    do {
        printf("\n--- Módulo de Fila de Espera ---\n");
        printf("1. Adicionar Cliente na Fila\n");
        printf("2. Chamar Próximo Cliente\n");
        printf("3. Mostrar Fila Atual\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        
        if (scanf("%d", &opcao) != 1) {
            while(getchar() != '\n'); // Limpa buffer se digitar letra
            continue;
        }
        while(getchar() != '\n'); // Limpa o 'enter' do buffer

        switch(opcao) {
            case 1:
                entrarNaFila(&inicioFila, &fimFila);
                break;
            case 2:
                chamarCliente(&inicioFila, &fimFila);
                break;
            case 3:
                mostrarFila(inicioFila);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);
}

// Enqueue: Adiciona um novo cliente no FINAL da fila
void entrarNaFila(Cliente** inicio, Cliente** fim) {
    // 1. Aloca memória para o novo cliente
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    if (novo == NULL) {
        printf("Erro: Memória cheia!\n");
        return;
    }

    // 2. Lê os dados do usuário
    printf("Nome do Cliente: ");
    fgets(novo->nome, 50, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0; // Remove o \n do final da string

    printf("Telefone: ");
    fgets(novo->telefone, 15, stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = 0;

    novo->proximo = NULL; // Como ele é o último, não aponta para ninguém

    // 3. Insere na estrutura da fila
    if (*inicio == NULL) {
        // Se a fila estava vazia, ele é o primeiro E o último
        *inicio = novo;
        *fim = novo;
    } else {
        // Se já tinha gente, o antigo último aponta para o novo...
        (*fim)->proximo = novo;
        // ...e o novo passa a ser o último
        *fim = novo;
    }

    printf(">>> Cliente %s registrado na fila com sucesso!\n", novo->nome);
}

// Dequeue: Remove o cliente do INÍCIO da fila (FIFO - First In, First Out)
void chamarCliente(Cliente** inicio, Cliente** fim) {
    if (*inicio == NULL) {
        printf("A fila está vazia! Ninguém para chamar.\n");
        return;
    }

    // Guarda o ponteiro do cliente que será atendido para liberar memória depois
    Cliente* temp = *inicio;

    printf("\n>>> CHAMANDO CLIENTE: %s (Tel: %s)\n", temp->nome, temp->telefone);
    printf("Por favor, dirija-se à mesa.\n");

    // O início da fila passa a ser o próximo da lista
    *inicio = (*inicio)->proximo;

    // Se a fila ficou vazia (início virou NULL), o fim também deve ser NULL
    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp); // Libera a memória do cliente removido
}

// Lista todos os clientes na ordem de chegada
void mostrarFila(Cliente* inicio) {
    if (inicio == NULL) {
        printf("Fila de espera vazia.\n");
        return;
    }

    printf("\n=== FILA DE ESPERA ATUAL ===\n");
    Cliente* atual = inicio;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%d. %s (Tel: %s)\n", posicao, atual->nome, atual->telefone);
        atual = atual->proximo;
        posicao++;
    }
    printf("============================\n");
}