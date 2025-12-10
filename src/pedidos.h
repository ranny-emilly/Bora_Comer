#ifndef PEDIDOS_H
#define PEDIDOS_H


typedef struct Pedido {
    int id;
    char descricao[100];
    float valor;
    struct Pedido* proximo; 
} Pedido;


void menuPedidos();
void adicionarPedido(Pedido** topo); 
void entregarPedido(Pedido** topo); 
void listarPedidos(Pedido* topo);   

#endif
