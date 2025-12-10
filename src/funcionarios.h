#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

typedef struct {
    int id;
    char nome[50];
    char cargo[30];
} Funcionario;

void menuFuncionarios();
void cadastrarFuncionario();
void listarFuncionarios();

#endif
