#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../h/terminal.h"
#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/senha.h"
#include "../h/livro.h"
#include "../h/help.h"

/*

    Estrutura de dados: Fila.
    Característica: FIFO (First IN, First OUT) / Primeiro a sair, primeiro a entrar.
    Implementação: Lista Duplamente Ligada.
    Inserção: Final.
    Remoçao: Ínicio. 

*/

void alterarLivro(LIVRO* primeiro, LIVRO* ultimo) {
    if (primeiro == NULL && ultimo == NULL);
}

void removerLivro(LIVRO** primeiro, LIVRO** ultimo) {
    if (primeiro == NULL && ultimo == NULL);
    if (*primeiro == *ultimo) {
        *primeiro = NULL;
        *ultimo = NULL;
    } else {
        *primeiro = (*primeiro)->livroDepois;
    }
    total--;
}

int main() {

    LIVRO *livroAtual = NULL;
    LEITOR **alguem = (LEITOR**) malloc(sizeof(LEITOR*));

    printf("Digite seu login: ");
    get((*alguem)->login);
    printf("Digite sua senha: ");
    esconde((*alguem)->senha);
    criptografa((*alguem)->senha);

    if (!estaCadastrado(*alguem)) cadastrarLeitor(*alguem);
    
    (*alguem)->primeiroLivro = NULL;
    (*alguem)->ultimoLivro = NULL;

    printf("\n\n%s, bem vindo a sua estante.\n",(*alguem)->login);
    printf(" (1) --- cadastre novos livros\n");
    printf(" (4) --- esses son seus livros\n");

    do {
        exibeLivros(*alguem);
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastraLivros(*alguem);
                break;
            case 2:
                // alterarLivro(firstLivro, lastLivro);
                break;
            case 3:
                // removerLivro(&firstLivro, &lastLivro);
                break;
            case 4:
                //ler();
                break;
            case 5:
                //Encerrar.
                break;
            default:
                break;
        }
    } while (opcao != 5);

    livroAtual = (*alguem)->primeiroLivro;
    while (livroAtual != NULL) {
        (*alguem)->primeiroLivro = livroAtual->livroDepois;
        free(livroAtual);
        livroAtual = (*alguem)->primeiroLivro;
    }
    free(alguem);
    return 0;
}
