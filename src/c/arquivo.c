#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../h/mainLib.h"
#include "../h/arquivo.h"
#include "../h/livro.h"

void arquivarLivros(LEITOR* umLeitor) {
    FILE* arquivo = fopen("resources/estante.csv", "a+");
    if (arquivo == false);

    fseek(arquivo, 0, SEEK_END);
    umLeitor->novoLivro = umLeitor->primeiroLivro;
    while (umLeitor->novoLivro != NULL) {
        if (!guardado(umLeitor)) {
            fprintf(arquivo, "%s;%03d;%s\n", umLeitor->login, umLeitor->novoLivro->idLivro, umLeitor->novoLivro->nome);
        }
        umLeitor->novoLivro = umLeitor->novoLivro->livroDepois;
    }
    fclose(arquivo);
}

void pegarLivros(LEITOR* umLeitor) {
    char linha[50];
    FILE* arquivo = fopen("resources/estante.csv", "r");
    if (arquivo == false);

    fseek(arquivo, 0, SEEK_SET);
    while(!feof(arquivo)) { // Enquanto o caracter atual for diferente do final do arquivo.
        fscanf(arquivo, "%s", linha);
        if (strstr(linha, umLeitor->login)) {
            strcpy(umLeitor->biblioteca, linha);
            umLeitor->ehArquivo = true;
            cadastraLivros(umLeitor);
        }
    }
    fclose(arquivo);
}

void cadastrarLeitor(LEITOR* umLeitor) {
    FILE* arquivo = fopen("resources/leitores.csv", "a+");
    if (arquivo == false);

    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%s;%s\n", umLeitor->login, umLeitor->senha);
    fclose(arquivo);
}

int cadastrado(LEITOR* umLeitor) {
    char linha[50];
    int achei = false;
    FILE* arquivo = fopen("resources/leitores.csv", "r");
    if (arquivo == false);

    fseek(arquivo, 0, SEEK_SET);
    while(!feof(arquivo)) {
        fscanf(arquivo, "%s", linha);
        if (strstr(linha, umLeitor->login) && strstr(linha, umLeitor->senha)) {
            achei = true;
            break;
        }    
    }
    fclose(arquivo);
    return achei;
}

int guardado(LEITOR* umLeitor) {
    char linha[50];
    int achei = false;
    FILE* arquivo = fopen("resources/estante.csv", "r");
    if (arquivo == false);

    fseek(arquivo, 0, SEEK_SET);
    while(!feof(arquivo)) {         
        fscanf(arquivo, "%s", linha);
        if (strstr(linha, umLeitor->login)  && strstr(linha, umLeitor->novoLivro->nome)) {
            achei = true;
            break;
        }    
    }
    fclose(arquivo);
    return achei;
}