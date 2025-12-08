#ifndef CARDAPIO_H
#define CARDAPIO_H

typedef struct {
    int id;
    char nome[50];
    float preco;
    char categoria[30]; // Ex: Bebida, Prato Principal
} ItemCardapio;

// Protótipos
void menuCardapio();
void adicionarItem();
void verCardapio();

#endif
