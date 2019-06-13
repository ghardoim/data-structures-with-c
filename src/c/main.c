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
    Arquitetura trabalhada com o objeto 'Livro': 

        Estrutura de dados: Fila.
        Característica: FIFO (First IN, First OUT) / Primeiro a sair, primeiro a entrar.
        Implementação: Lista Duplamente Ligada.
        Inserção: Final.
        Remoçao: Ínicio.
*/

int main() {

    LEITOR **alguem = (LEITOR**) malloc(sizeof(LEITOR*));

    printf("\nDigite seu login: ");
    get((*alguem)->login);
    printf("\nDigite sua senha: ");
    esconde((*alguem)->senha);
    criptografa((*alguem)->senha);

    if (!cadastrado(*alguem)) cadastrarLeitor(*alguem);
    
    (*alguem)->primeiroLivro = NULL;
    (*alguem)->ultimoLivro = NULL;
    (*alguem)->novoLivro = NULL;

    pegarLivros(*alguem);

    do {
        // int number = 0;
        system("clear");
        printf("\n\n%s, os livros da sua estante:\n",(*alguem)->login);
        exibeLivros(*alguem);
        printf("\n\n\t\t(1) Adicione novos livros!");
        printf("\n\t\t(2) Remova livros antigos!");
        printf("\n\nDigite o que deseja fazer: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                (*alguem)->ehArquivo = false;
                cadastraLivros(*alguem);
                break;
            /*
            case 2:
                printf("\nQual o livro que deseja alterar: ");
                scanf("%d", &number);
                alterarLivro(*alguem, number);
                break;
            */
            case 2:
                removeLivros(*alguem);
                break;
            default:
                break;
        }
    } while (opcao == 2 || opcao == 1);

    arquivarLivros(*alguem);

    (*alguem)->novoLivro = (*alguem)->primeiroLivro;
    while ((*alguem)->novoLivro != NULL) {
        (*alguem)->primeiroLivro = (*alguem)->novoLivro->livroDepois;
        free((*alguem)->novoLivro);
        (*alguem)->novoLivro = (*alguem)->primeiroLivro;
    }
    free(alguem);
    return 0;
}