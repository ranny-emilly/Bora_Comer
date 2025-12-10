#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"

static const char *arquivoFuncionarios = "funcionarios.db";

void menuFuncionarios() {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n--- Módulo de Funcionários ---\n");
        printf("1. Cadastrar Funcionário\n");
        printf("2. Listar Funcionários\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            cadastrarFuncionario();
        } else if (opcao == 2) {
            listarFuncionarios();
        }
    }
}

void cadastrarFuncionario() {
    Funcionario f;
    FILE *fp = fopen(arquivoFuncionarios, "ab");
    if (!fp) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\n--- Cadastro de Funcionário ---\n");

    printf("ID: ");
    scanf("%d", &f.id);
    getchar();

    printf("Nome: ");
    fgets(f.nome, 50, stdin);
    f.nome[strcspn(f.nome, "\n")] = 0;

    printf("Cargo: ");
    fgets(f.cargo, 30, stdin);
    f.cargo[strcspn(f.cargo, "\n")] = 0;

    fwrite(&f, sizeof(Funcionario), 1, fp);
    fclose(fp);

    printf("Funcionário cadastrado com sucesso!\n");
}

void listarFuncionarios() {
    Funcionario f;
    FILE *fp = fopen(arquivoFuncionarios, "rb");

    if (!fp) {
        printf("\nNenhum funcionário cadastrado ainda.\n");
        return;
    }

    printf("\n--- Lista de Funcionários ---\n");

    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        printf("\nID: %d\n", f.id);
        printf("Nome: %s\n", f.nome);
        printf("Cargo: %s\n", f.cargo);
    }

    fclose(fp);
}
