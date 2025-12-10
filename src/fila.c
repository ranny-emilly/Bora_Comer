#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


static Cliente* inicioFila = NULL;
static Cliente* fimFila = NULL;

void menuFila() {
    int opcao;
    do {
        printf("\n--- Modulo de Fila de Espera ---\n");
        printf("1. Adicionar Cliente na Fila\n");
        printf("2. Chamar Proximo Cliente\n");
        printf("3. Mostrar Fila Atual\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        
        if (scanf("%d", &opcao) != 1) {
            while(getchar() != '\n'); 
            continue;
        }
        while(getchar() != '\n'); 

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
                printf("Opção invalida!\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);
}


void entrarNaFila(Cliente** inicio, Cliente** fim) {
   
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    if (novo == NULL) {
        printf("Erro: Memoria cheia!\n");
        return;
    }

    
    printf("Nome do Cliente: ");
    fgets(novo->nome, 50, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0; 

    printf("Telefone: ");
    fgets(novo->telefone, 15, stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = 0;

    novo->proximo = NULL; 

    
    if (*inicio == NULL) {
        
        *inicio = novo;
        *fim = novo;
    } else {
        
        (*fim)->proximo = novo;
        
        *fim = novo;
    }

    printf(">>> Cliente %s registrado na fila com sucesso!\n", novo->nome);
}


void chamarCliente(Cliente** inicio, Cliente** fim) {
    if (*inicio == NULL) {
        printf("A fila está vazia! Ninguém para chamar.\n");
        return;
    }

    
    Cliente* temp = *inicio;

    printf("\n>>> CHAMANDO CLIENTE: %s (Tel: %s)\n", temp->nome, temp->telefone);
    printf("Por favor, dirija-se a mesa.\n");

    
    *inicio = (*inicio)->proximo;

  
    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp); 
}


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