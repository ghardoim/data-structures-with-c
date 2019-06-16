#include <stdlib.h>
#include <stdio.h>
#include "../h/help.h"
#include "../h/leitor.h"
#include "../h/mainLib.h"

void libera(LEITOR* umLeitor) {
    umLeitor->novoLivro = umLeitor->primeiroLivro;
    while (umLeitor->novoLivro != NULL) {
        umLeitor->primeiroLivro = umLeitor->novoLivro->livroDepois;
        free(umLeitor->novoLivro);
        umLeitor->novoLivro = umLeitor->primeiroLivro;
    }
    free(umLeitor);
}

/*
void adicionarAmigos(LEITOR* umLeitorRaiz) {
    if (umLeitorRaiz == NULL) {
        umLeitorRaiz = (LEITOR*) malloc(sizeof(LEITOR*)); 
        printf("Informe o nome do seu amigo: ");
        get(umLeitorRaiz->login);

    } else {
        if ((totalLivros % 2) == 0 ? false : true) {
            printf("\t( -> )\t");
            adicionarAmigos(umLeitorRaiz->esquerda);
        } else {
            printf("\t( <- )\t");
            adicionarAmigos(umLeitorRaiz->direita);
        }        
    }
}
void listarAmigos(LEITOR* umLeitorRaiz) {
    if (umLeitorRaiz != NULL) {
        printf("%s", umLeitorRaiz->login);
        listarAmigos(umLeitorRaiz->direita);
        listarAmigos(umLeitorRaiz->esquerda);
    }
}
 */