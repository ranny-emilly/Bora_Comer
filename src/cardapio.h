#ifndef CARDAPIO_H
#define CARDAPIO_H


// Estrutura para itens do cardápio (lista)
typedef struct ItemCardapio {
int id;
char nome[50];
float preco;
char categoria[30];
struct ItemCardapio* proximo;
} ItemCardapio;

// Protótipos
void menuCardapio();
void adicionarItem();
void removerItem();
void verCardapio();

#endif


