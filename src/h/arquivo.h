#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include "mainLib.h"

// Funções de arquivo.
void cadastrarLeitor(LEITOR* umLeitor);
int estaCadastrado(LEITOR* umLeitor);
void escrever(LIVRO* umLivro);
void ler();

#endif