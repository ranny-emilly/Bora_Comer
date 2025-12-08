#ifndef PEDIDOS_H
#define PEDIDOS_H

// Estrutura de Nó para a Pilha (Stack)
// Requisito 4: Pedidos organizados por PILHA
typedef struct Pedido {
    int id;
    char descricao[100];
    float valor;
    struct Pedido* proximo; // Ponteiro para o pedido de baixo
} Pedido;

// Protótipos
void menuPedidos();
void adicionarPedido(Pedido** topo); // Push (Empilhar)
void entregarPedido(Pedido** topo);  // Pop (Desempilhar)
void listarPedidos(Pedido* topo);    // Peek (Ver a pilha)

#endif
