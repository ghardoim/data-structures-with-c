#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include "mainLib.h"

// Funções de arquivo.
void cadastrarLeitor(LEITOR* umLeitor);
void arquivarLivros(LEITOR* leitor);
void pegarLivros(LEITOR* umLeitor);
int cadastrado(LEITOR* umLeitor);
int guardado(LEITOR* umLeitor);

#endif