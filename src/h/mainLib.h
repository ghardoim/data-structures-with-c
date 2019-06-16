#ifndef _MAINLIB_H_
#define _MAINLIB_H_

#define _CHAR 50
#define IDADE(anoNasc) (2019 - anoNasc)
#define true 1
#define false 0

typedef struct data {
    int ano, mes, dia;
}DATA;

typedef struct livro {
    char nome[_CHAR], genero[_CHAR], autor[_CHAR], editora[_CHAR];
    struct livro *livroAntes, *livroDepois;
    int idLivro;
}LIVRO;

typedef struct leitor {
    char gambiarra[_CHAR], login[_CHAR], senha[_CHAR];
    LIVRO *primeiroLivro, *ultimoLivro, *novoLivro;
    struct leitor *direita, *esquerda;
    char biblioteca[_CHAR];
    DATA dataNascimento;
    int ehArquivo;
}LEITOR;

int opcao, totalLivros;

#endif