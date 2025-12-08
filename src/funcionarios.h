#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

// Estrutura para um funcionário
typedef struct {
    int id;
    char nome[50];
    char cargo[30];
} Funcionario;

// Protótipos das funções (O "Menu" do que este módulo faz)
void menuFuncionarios();
void cadastrarFuncionario();
void listarFuncionarios();

#endif
