#ifndef _LIVRO_H_
#define _LIVRO_H_

void alterarLivro(LEITOR* umLeitor, int number);
void addLivro(LEITOR* umLeitor, char linha[]);
void cadastraLivros(LEITOR* umLeitor);
void removeLivros(LEITOR* umLeitor);
void exibeLivros(LEITOR* umLeitor);
int semLivros(LEITOR* umLeitor);

#endif