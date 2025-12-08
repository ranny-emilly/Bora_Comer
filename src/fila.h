#ifndef FILA_H
#define FILA_H

// Estrutura de Nó para a Fila (Queue) - Implementa uma Lista Encadeada
// Requisito 3: Fila de espera de clientes
typedef struct Cliente {
    char nome[50];
    char telefone[15];
    struct Cliente* proximo; // Ponteiro para o próximo cliente na fila
} Cliente;

// Protótipos das funções que serão usadas pelo menu e outros módulos
void menuFila();
void entrarNaFila(Cliente** inicio, Cliente** fim); // Função para adicionar (Enqueue)
void chamarCliente(Cliente** inicio, Cliente** fim); // Função para remover (Dequeue)
void mostrarFila(Cliente* inicio); // Função para listar

#endif