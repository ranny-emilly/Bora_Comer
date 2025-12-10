#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cardapio.h"


static ItemCardapio* inicioCardapio = NULL;
static int proximoIdItem = 1;
static void inserirFim(ItemCardapio* novo);

void menuCardapio() {
    int opcao;
    do {
        printf("\nCardapio\n");
        printf("1. Adicionar item ao cardapio\n");
        printf("2. Remover item do cardapio\n");
        printf("3. Ver cardapio\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); 

        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                verCardapio();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Por favor selecione uma das opções acima\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);
}


void adicionarItem() {
    ItemCardapio* novo = (ItemCardapio*)malloc(sizeof(ItemCardapio));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    novo->id = proximoIdItem++;

    printf("Nome do item: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0;

    printf("Categoria (ex: Bebida, Prato principal, Sobremesa): ");
    fgets(novo->categoria, sizeof(novo->categoria), stdin);
    novo->categoria[strcspn(novo->categoria, "\n")] = 0;

    printf("Valor: R$ ");
    if (scanf("%f", &novo->preco) != 1) {
        printf("Preco invalido!\n");
        free(novo);
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); 

    novo->proximo = NULL;

    inserirFim(novo);

    printf("Item adicionado: [%d] %s — %s — R$ %.2f\n", novo->id, novo->nome, novo->categoria, novo->preco);
}


void removerItem() {
    if (inicioCardapio == NULL) {
        printf("\nO cardapio está vazio.\n");
        return;
    }

    int id;
    printf("Digite o ID do item a remover: ");
    if (scanf("%d", &id) != 1) {
        printf("ID invalido.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    ItemCardapio* atual = inicioCardapio;
    ItemCardapio* anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Item com ID %d nao encontrado.\n", id);
        return;
    }

    if (anterior == NULL) {
        inicioCardapio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Item removido: [%d] %s — %s — R$ %.2f\n", atual->id, atual->nome, atual->categoria, atual->preco);
    free(atual);
}


void verCardapio() {
    if (inicioCardapio == NULL) {
        printf("\nO cardapio esta vazio.\n");
        return;
    }

    char categorias[100][30];
    int nCats = 0;

    ItemCardapio* p = inicioCardapio;
    while (p != NULL && nCats < 100) {
        int achou = 0;
        for (int i = 0; i < nCats; ++i) {
            if (strcmp(categorias[i], p->categoria) == 0) { achou = 1; break; }
        }
        if (!achou) {
            strncpy(categorias[nCats], p->categoria, sizeof(categorias[nCats]) - 1);
            categorias[nCats][sizeof(categorias[nCats]) - 1] = '\0';
            nCats++;
        }
        p = p->proximo;
    }

    printf("\n========= CARDAPIO =========\n");
    for (int i = 0; i < nCats; ++i) {
        printf("\n--- %s ---\n", categorias[i][0] != '\0' ? categorias[i] : "Geral");

        int contador = 1;
        ItemCardapio* q = inicioCardapio;
        while (q != NULL) {
            if (strcmp(q->categoria, categorias[i]) == 0) {
                printf("%2d) %s\n    R$ %.2f\n", contador, q->nome, q->preco);
                contador++;
            }
            q = q->proximo;
        }
    }
    printf("\n============================================\n");
}


static void inserirFim(ItemCardapio* novo) {
    if (inicioCardapio == NULL) {
        inicioCardapio = novo;
        return;
    }
    ItemCardapio* atual = inicioCardapio;
    while (atual->proximo != NULL) atual = atual->proximo;
    atual->proximo = novo;
}
