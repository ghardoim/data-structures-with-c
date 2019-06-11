#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/help.h"
#include <stdlib.h>
#include <stdio.h>

void cadastraLivros(LEITOR* umLeitor) {

    umLeitor->novoLivro = (LIVRO*) malloc(sizeof(LIVRO));
    umLeitor->novoLivro->id++;

    printf("\nDigite o nome do seu livro: ");
    get(umLeitor->novoLivro->nome);

    if (umLeitor->primeiroLivro == NULL && umLeitor->ultimoLivro == NULL) {
        umLeitor->primeiroLivro = umLeitor->novoLivro;
        umLeitor->novoLivro->livroAntes = NULL;   
    } else {
        umLeitor->novoLivro->livroAntes = umLeitor->ultimoLivro;
        umLeitor->ultimoLivro->livroDepois = umLeitor->novoLivro;
    }
    umLeitor->ultimoLivro = umLeitor->novoLivro;
    umLeitor->novoLivro->livroDepois = NULL;

    arquivarLivro(umLeitor);
    system("pause");
}

void exibeLivros(LEITOR* umLeitor) {
    if (umLeitor->primeiroLivro == NULL && umLeitor->ultimoLivro == NULL) return;

    umLeitor->novoLivro = umLeitor->ultimoLivro;
    while (umLeitor->novoLivro != NULL) {
        printf("livro: %s", umLeitor->novoLivro->nome);
        umLeitor->novoLivro = umLeitor->novoLivro->livroAntes;    
    }
}

void removeLivros(LEITOR* umLeitor) {
    if (umLeitor->primeiroLivro == NULL && umLeitor->ultimoLivro == NULL) return;

    if (umLeitor->primeiroLivro == umLeitor->ultimoLivro) {
        umLeitor->primeiroLivro = NULL;
        umLeitor->ultimoLivro = NULL;
    } else {
        umLeitor->primeiroLivro = umLeitor->primeiroLivro->livroDepois;
        umLeitor->primeiroLivro->livroAntes = NULL;
    }
}