#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include "mainLib.h"

// Funções de arquivo.
void cadastrarLeitor(LEITOR* umLeitor);
int estaCadastrado(LEITOR* umLeitor);
void arquivarLivro(LEITOR* leitor);
void ler();

#endif