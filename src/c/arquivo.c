#include <stdio.h>
#include <stdlib.h>

#include "../h/mainLib.h"
#include "../h/interface.h"

void escreveNoArquivo(PACIENTE* umPaciente) {
    FILE* arquivo = fopen("resrc/pacientes.csv", "r+");
    if (arquivo == 0) problemaComArquivo();

    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%s;%d\n", umPaciente->individuo.nome, umPaciente->individuo.idade);
    
    fclose(arquivo);
}

void lerDoArquivo() {
    char linhaDoArquivo[50];

    FILE* arquivo = fopen("resrc/pacientes.csv", "r");
    if (arquivo == 0) problemaComArquivo();

    fseek(arquivo, 0, SEEK_SET);
    while(fgetc(arquivo) != EOF) { //Enquanto o caracter atual for diferente do final do arquivo.
        fscanf(arquivo, "%s", linhaDoArquivo);
        printf("Linha do arquivo --> %s\n", linhaDoArquivo);   
    }

    fclose(arquivo);
    system("pause");
}