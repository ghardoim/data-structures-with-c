#include <stdlib.h>
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