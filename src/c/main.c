#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../h/terminal.h"
#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/leitor.h"
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
    (*alguem)->primeiroLivro = NULL;
    (*alguem)->ultimoLivro = NULL;
    (*alguem)->novoLivro = NULL;
    
    printf("\nDigite seu login: ");
    get((*alguem)->login);
    printf("\nDigite sua senha: ");
    esconde((*alguem)->senha);
    criptografa((*alguem)->senha);

    if (!cadastrado(*alguem)) cadastrarLeitor(*alguem);
    pegarLivros(*alguem);

    do {
        system("clear");
        printf("\n\n%s, os livros da sua estante:\n",(*alguem)->login);
        exibeLivros(*alguem);
        printf("\n\n\t\t(1) Adicione novos livros!");
        printf("\n\t\t(2) Remova livros antigos!");
        
        printf("\n\n\t\t(3) Sair");
        printf("\n\nDigite o que deseja fazer: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                (*alguem)->ehArquivo = false;
                cadastraLivros(*alguem);
                break;
            case 2:
                removeLivros(*alguem);
                break;
            case 3:
                break;
            default:
                printf("\n\tEscolha estranha hein!");
                system("sleep 1");
                break;
        }
    } while (opcao != 3);

    arquivarLivros(*alguem);
    libera(*alguem);   
    return 0;
}