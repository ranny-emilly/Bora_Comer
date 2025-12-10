#ifndef FILA_H
#define FILA_H


typedef struct Cliente {
    char nome[50];
    char telefone[15];
    struct Cliente* proximo; 
} Cliente;


void menuFila();
void entrarNaFila(Cliente** inicio, Cliente** fim); 
void chamarCliente(Cliente** inicio, Cliente** fim); 
void mostrarFila(Cliente* inicio); 

#endif