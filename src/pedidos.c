#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "pedidos.h"

static int proximo_id = 1;

void menuPedidos() {
    int opcao;
    Pedido* topo_pilha = NULL; 

    do {
        printf("\n--- Modulo de Pedidos/Cozinha ---\n");
        printf("1. Adicionar Novo Pedido \n");
        printf("2. Entregar Pedido \n");
        printf("3. Listar Todos os Pedidos \n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPedido(&topo_pilha);
                break;
            case 2:
                entregarPedido(&topo_pilha);
                break;
            case 3:
                listarPedidos(topo_pilha);
                break;
            case 0:
                printf("Voltando ao menu principal.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    
}


void adicionarPedido(Pedido** topo) {
   
    Pedido* novo_pedido = (Pedido*)malloc(sizeof(Pedido));

    if (novo_pedido == NULL) {
        printf("ERRO\n");
        return;
    }

    printf("\n--- Adicionar Novo Pedido ---\n");
    novo_pedido->id = proximo_id++;

    
    while (getchar() != '\n'); 

    printf("Descricao do Pedido: ");
 
    fgets(novo_pedido->descricao, 100, stdin);
  
    novo_pedido->descricao[strcspn(novo_pedido->descricao, "\n")] = 0; 

    printf("Valor do Pedido: R$ ");
    scanf("%f", &novo_pedido->valor);

   
    novo_pedido->proximo = *topo;

   
    *topo = novo_pedido; 

    printf("\n Pedido %d (\"%s\") adicionado.\n", novo_pedido->id, novo_pedido->descricao);
}


void entregarPedido(Pedido** topo) {
    if (*topo == NULL) {
        printf("\nA pilha de pedidos esta vazia. Nenhum pedido para entregar.\n");
        return;
    }

   
    Pedido* temp = *topo;

   
    *topo = temp->proximo;

   
    printf("\n Pedido Entregue/Removido:\n");
    printf("ID: %d\n", temp->id);
    printf("Descricao: %s\n", temp->descricao);
    printf("Valor: R$ %.2f\n", temp->valor);

    free(temp);
    printf("\nPedido liberado.\n");
}


void listarPedidos(Pedido* topo) {
    if (topo == NULL) {
        printf("\nA pilha de pedidos esta vazia.\n");
        return;
    }

    printf("\nPedidos na Pilha\n");

    Pedido* atual = topo;

   
    while (atual != NULL) {
        printf("--- Pedido ID: %d (R$ %.2f) ---\n", atual->id, atual->valor);
        printf("Descricao: %s\n", atual->descricao);
       
        atual = atual->proximo; 
    }
    printf("---------------------------------------------\n");
}