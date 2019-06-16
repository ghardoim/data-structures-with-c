#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/livro.h"
#include "../h/help.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void cadastraLivros(LEITOR* umLeitor) {
    fflush(stdin);
    umLeitor->novoLivro = (LIVRO*) malloc(sizeof(LIVRO));
    umLeitor->novoLivro->idLivro = ++totalLivros;

    if (umLeitor->ehArquivo) {
        strcpy(umLeitor->login, strtok(umLeitor->biblioteca, ";"));
        strtok(NULL, ";");
        strcpy(umLeitor->novoLivro->nome, strtok(NULL, ";"));

    } else {
        printf("\nDigite o nome do seu livro: ");
        get(umLeitor->novoLivro->nome);
    }

    if (semLivros(umLeitor)) {
        umLeitor->primeiroLivro = umLeitor->novoLivro;
        umLeitor->novoLivro->livroAntes = NULL;   
    } else {
        umLeitor->novoLivro->livroAntes = umLeitor->ultimoLivro;
        umLeitor->ultimoLivro->livroDepois = umLeitor->novoLivro;
    }
    umLeitor->ultimoLivro = umLeitor->novoLivro;
    umLeitor->novoLivro->livroDepois = NULL;
}

void exibeLivros(LEITOR* umLeitor) {
    fflush(stdin);
    if (semLivros(umLeitor)) {
        printf("\n\tEstante vazia! Adicione alguns livros!!");
        return;
    }

    umLeitor->novoLivro = umLeitor->ultimoLivro;
    while (umLeitor->novoLivro != NULL) {
        printf("\n\tId: %d | Livro: %s",umLeitor->novoLivro->idLivro, umLeitor->novoLivro->nome);
        umLeitor->novoLivro = umLeitor->novoLivro->livroAntes;    
    }
}

void removeLivros(LEITOR* umLeitor) {
    if (semLivros(umLeitor)) {
        printf("\n\tEstante vazia! Adicione alguns livros!!");
        return;
    }
    if (umLeitor->primeiroLivro == umLeitor->ultimoLivro) {
        umLeitor->primeiroLivro = NULL;
        umLeitor->ultimoLivro = NULL;
    } else {
        umLeitor->primeiroLivro = umLeitor->primeiroLivro->livroDepois;
        umLeitor->primeiroLivro->livroAntes = NULL;
    }
}

void alterarLivro(LEITOR* umLeitor, int number) {
    if (semLivros(umLeitor)) {
        printf("\n\tEstante vazia! Adicione alguns livros!!");
        return;
    }
    umLeitor->novoLivro = umLeitor->primeiroLivro;
    while (umLeitor->novoLivro->idLivro != number) {
        umLeitor->novoLivro = umLeitor->novoLivro->livroDepois;
    }
    char escolha;
    printf("\n'A'utor || 'G'enero || 'E'ditora\nO que falta nesse livro? ");
    fflush(stdin);
    scanf("%c", &escolha);
    fflush(stdin);
    switch (escolha) {
    case 'a':
    case 'A':
        printf("\nDiga o autor desse livro: ");
        get(umLeitor->novoLivro->autor);
        break;

    case 'g':
    case 'G':
        printf("\nDiga o genero desse livro: ");
        get(umLeitor->novoLivro->genero);
        break;
    
    case 'e':
    case 'E':
        printf("\nDiga a editora desse livro: ");
        get(umLeitor->novoLivro->editora);
    default:
        printf("\nEscolha errada! Nada foi adicionado!");
        break;
    }
}

int semLivros(LEITOR* umLeitor) {
    return (umLeitor->primeiroLivro == NULL && umLeitor->ultimoLivro == NULL);
}