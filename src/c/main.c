#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../h/terminal.h"
#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/senha.h"

/*

    Estrutura de dados: Fila.
    Característica: FIFO (First IN, First OUT) / Primeiro a sair, primeiro a entrar.
    Implementação: Lista Duplamente Ligada.
    Inserção: Final.
    Remoçao: Ínicio. 

*/

void cadastrarLivro(LIVRO** primeiro, LIVRO** ultimo) {

    LIVRO *novo = (LIVRO*) malloc(sizeof(LIVRO));

    if (*primeiro == NULL && *ultimo ==NULL) {
        *primeiro = novo;
        novo->livroAntes = NULL;   
    } else {
        novo->livroAntes = *ultimo;
        (*ultimo)->livroDepois = novo;
    }
    *ultimo = novo;
    novo->livroDepois = NULL;

    escrever(novo);
    system("pause");
}

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

void exibirLivro(LIVRO* primeiro, LIVRO* ultimo) {
    system("clear");
    if (primeiro == NULL && ultimo == NULL);
    while (primeiro != NULL && ultimo != NULL){
        if (primeiro->livroDepois == NULL) break;
        primeiro = primeiro->livroDepois;
    }
    system("pause");    
}

int main() {

    LIVRO *livroAtual = NULL;
    LEITOR **alguem = (LEITOR**) malloc(sizeof(LEITOR*));

    printf("Digite seu login: ");
    scanf("%s", (*alguem)->login);
    printf("Digite sua senha: ");
    escondeSenha((*alguem)->senha);

    if (!estaCadastrado(*alguem)) {
        printf("Vamos realizar seu cadastro");
        cadastrarLeitor(*alguem);

    }


/*
    do {
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarLivro(&firstLivro, &lastLivro);
                break;
            case 2:
                alterarLivro(firstLivro, lastLivro);
                break;
            case 3:
                removerLivro(&firstLivro, &lastLivro);
                break;
            case 4:
                //ler();
                exibirLivro(firstLivro, lastLivro);
                break;
            case 5:
                //Encerrar.
                break;
            default:
                break;
        }
    } while (opcao != 5);
*/
    livroAtual = (*alguem)->primeiroLivro;
    while (livroAtual != NULL) {
        (*alguem)->primeiroLivro = livroAtual->livroDepois;
        free(livroAtual);
        livroAtual = (*alguem)->primeiroLivro;
    }

    free(alguem);
    return 0;
}
