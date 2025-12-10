#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

typedef struct {
    char cpf[20];
    char nome[50];
    char cargo[30];
} Funcionario;

void menuFuncionarios();
void cadastrarFuncionario();
void listarFuncionarios();
void removerFuncionario();

#endif
