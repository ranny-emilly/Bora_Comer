#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "pedidos.h"

// Variável para gerar IDs de pedidos sequenciais
static int proximo_id = 1;

void menuPedidos() {
    int opcao;
    Pedido* topo_pilha = NULL; 

    do {
        printf("\n--- Módulo de Pedidos/Cozinha ---\n");
        printf("1. Adicionar Novo Pedido (PUSH)\n");
        printf("2. Entregar Pedido (POP)\n");
        printf("3. Listar Todos os Pedidos (PEEK)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
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
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    
}

// Implementação PUSH (Empilhar)
void adicionarPedido(Pedido** topo) {
    // 1. Aloca memória para o novo nó/pedido
    Pedido* novo_pedido = (Pedido*)malloc(sizeof(Pedido));

    if (novo_pedido == NULL) {
        printf("ERRO: Falha na alocação de memória para o novo pedido.\n");
        return;
    }

    // 2. Coleta dados do pedido
    printf("\n--- Adicionar Novo Pedido ---\n");
    novo_pedido->id = proximo_id++;

    // Limpa o buffer de entrada antes de ler a string
    while (getchar() != '\n'); 

    printf("Descrição do Pedido (max 99 caracteres): ");
    // Lê a descrição, limitando o tamanho para evitar buffer overflow
    fgets(novo_pedido->descricao, 100, stdin);
    // Remove o '\n' lido pelo fgets, se presente
    novo_pedido->descricao[strcspn(novo_pedido->descricao, "\n")] = 0; 

    printf("Valor do Pedido: R$ ");
    scanf("%f", &novo_pedido->valor);

    // 3. O novo pedido aponta para o antigo topo (o pedido "de baixo")
    novo_pedido->proximo = *topo;

    // 4. Atualiza o topo da pilha para o novo pedido
    *topo = novo_pedido; 

    printf("\n✅ Pedido %d (\"%s\") adicionado ao topo da pilha.\n", novo_pedido->id, novo_pedido->descricao);
}

// Implementação POP (Desempilhar)
void entregarPedido(Pedido** topo) {
    if (*topo == NULL) {
        printf("\n🚫 A pilha de pedidos está vazia. Nenhum pedido para entregar.\n");
        return;
    }

    // 1. Cria um ponteiro temporário para o nó do topo (o pedido a ser removido)
    Pedido* temp = *topo;

    // 2. Atualiza o topo da pilha para o próximo nó (o pedido "de baixo")
    *topo = temp->proximo;

    // 3. Exibe informações do pedido que está sendo removido/entregue
    printf("\n🚚 Pedido Entregue/Removido:\n");
    printf("ID: %d\n", temp->id);
    printf("Descrição: %s\n", temp->descricao);
    printf("Valor: R$ %.2f\n", temp->valor);

    // 4. Libera a memória alocada para o nó removido
    free(temp);
    printf("\n✅ Pedido liberado da memória.\n");
}

// Implementação PEEK/Listagem
void listarPedidos(Pedido* topo) {
    if (topo == NULL) {
        printf("\n🚫 A pilha de pedidos está vazia.\n");
        return;
    }

    printf("\n--- 🧾 Pedidos na Pilha (Topo para Baixo) ---\n");

    Pedido* atual = topo;

    // Percorre a lista/pilha a partir do topo
    while (atual != NULL) {
        printf("--- Pedido ID: %d (R$ %.2f) ---\n", atual->id, atual->valor);
        printf("Descrição: %s\n", atual->descricao);
        // Avança para o próximo pedido ("de baixo")
        atual = atual->proximo; 
    }
    printf("---------------------------------------------\n");
}