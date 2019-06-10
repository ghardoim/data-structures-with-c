#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../h/mainLib.h"

void arquivarLivro(LEITOR* umLeitor) {
    FILE* arquivo = fopen("resources/estante.csv", "a+");
    if (arquivo == 0);

    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%s;%05d;%s\n", umLeitor->login, umLeitor->novoLivro->id, umLeitor->novoLivro->nome);
    fclose(arquivo);
}

void ler() {
    char linha[50];

    FILE* arquivo = fopen("resources/estante.csv", "r");
    if (arquivo == 0);

    fseek(arquivo, 0, SEEK_SET);
    while(!feof(arquivo)) { // Enquanto o caracter atual for diferente do final do arquivo.
        fscanf(arquivo, "%s", linha);
        printf("Linha do arquivo --> %s\n", linha);   
    }

    fclose(arquivo);
    system("pause");
}

void cadastrarLeitor(LEITOR* umLeitor) {
    FILE* arquivo = fopen("resources/leitores.csv", "a+");
    if (arquivo == 0);

    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%s;%s\n", umLeitor->login, umLeitor->senha);
    fclose(arquivo);
}

int estaCadastrado(LEITOR* umLeitor) {
    char linha[50];
    int achei = 0;
    FILE* arquivo = fopen("resources/leitores.csv", "r");
    if (arquivo == 0);

    fseek(arquivo, 0, SEEK_SET);
    while(!feof(arquivo)) { // Enquanto o caracter atual for diferente do final do arquivo.           
        fscanf(arquivo, "%s", linha);
        if (strstr(linha, umLeitor->login) != NULL && strstr(linha, umLeitor->senha)) {
            achei = 1;
            break;
        }    
    }
    fclose(arquivo);
    return achei;
}