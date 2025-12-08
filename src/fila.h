#ifndef FILA_H
#define FILA_H

// Estrutura de Nó para a Fila (Queue)
// Requisito 3: Fila de espera de clientes
typedef struct Cliente {
    char nome[50];
    char telefone[15];
    struct Cliente* proximo;
} Cliente;

// Protótipos
void menuFila();
void entrarNaFila(Cliente** inicio, Cliente** fim); // Enqueue
void chamarCliente(Cliente** inicio, Cliente** fim); // Dequeue
void mostrarFila(Cliente* inicio);

#endif
