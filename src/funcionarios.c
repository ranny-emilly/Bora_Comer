#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"

static const char *arquivoFuncionarios = "funcionarios.db";

void menuFuncionarios() {
    int opcao;

    do {
        printf("\n--- Modulo de Funcionarios ---\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Listar Funcionarios\n");
        printf("3. Remover Funcionario\n");
        printf("0. Voltar\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (opcao == 1) {
            cadastrarFuncionario();
        } else if (opcao == 2) {
            listarFuncionarios();
        } else if (opcao == 3) {
            removerFuncionario();
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);
}

void cadastrarFuncionario() {
    Funcionario f;
    FILE *fp = fopen(arquivoFuncionarios, "ab");
    if (!fp) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("\n--- Cadastro de Funcionario ---\n");

    printf("CPF (somente numeros): ");
    fgets(f.cpf, sizeof(f.cpf), stdin);
    f.cpf[strcspn(f.cpf, "\n")] = 0;

    printf("Nome: ");
    fgets(f.nome, sizeof(f.nome), stdin);
    f.nome[strcspn(f.nome, "\n")] = 0;

    printf("Cargo: ");
    fgets(f.cargo, sizeof(f.cargo), stdin);
    f.cargo[strcspn(f.cargo, "\n")] = 0;

    fwrite(&f, sizeof(Funcionario), 1, fp);
    fclose(fp);

    printf("Funcionario cadastrado com sucesso!\n");
}

void listarFuncionarios() {
    Funcionario f;
    FILE *fp = fopen(arquivoFuncionarios, "rb");

    if (!fp) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    printf("\n========== LISTA DE FUNCIONARIOS ==========\n");

    int contador = 1;
    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        printf("\n%02d) CPF: %s\n", contador, f.cpf);
        printf("    Nome:  %s\n", f.nome);
        printf("    Cargo: %s\n", f.cargo);
        contador++;
    }

    printf("\n===========================================\n");

    fclose(fp);
}

void removerFuncionario() {
    char cpfBusca[20];
    Funcionario f;
    int achou = 0;

    FILE *fp = fopen(arquivoFuncionarios, "rb");
    if (!fp) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    FILE *temp = fopen("temp.db", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(fp);
        return;
    }

    printf("\nCPF do funcionario a remover: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    while (fread(&f, sizeof(Funcionario), 1, fp)) {
        if (strcmp(f.cpf, cpfBusca) == 0) {
            achou = 1;
        } else {
            fwrite(&f, sizeof(Funcionario), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(arquivoFuncionarios);
    rename("temp.db", arquivoFuncionarios);

    if (achou) {
        printf("Funcionario removido com sucesso.\n");
    } else {
        printf("Nenhum funcionario encontrado com esse CPF.\n");
    }
}
