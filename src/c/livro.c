#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/help.h"
#include <stdlib.h>
#include <stdio.h>

void cadastraLivros(LEITOR* umLeitor) {

    umLeitor->novoLivro = (LIVRO*) malloc(sizeof(LIVRO));
    umLeitor->novoLivro->id = total++;

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