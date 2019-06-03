#include <stdio.h>
#include <stdlib.h>

#include "../h/mainLib.h"

void escreveNoArquivo(PACIENTE* umPaciente) {
    FILE* arquivo = fopen("resrc/pacientes.csv", "a+");
    if (arquivo == 0);

    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%05d;%s;%d\n", umPaciente->id,
        umPaciente->individuo.nome,
        IDADE(umPaciente->individuo.dataNascimento.ano),
        IMC(umPaciente->individuo.altura, umPaciente->individuo.peso));
    
    fclose(arquivo);
}

void lerDoArquivo() {
    char linhaDoArquivo[50];

    FILE* arquivo = fopen("resrc/pacientes.csv", "r");
    if (arquivo == 0);

    fseek(arquivo, 0, SEEK_SET);
    while(fgetc(arquivo) != EOF) { //Enquanto o caracter atual for diferente do final do arquivo.
        fscanf(arquivo, "%s", linhaDoArquivo);
        printf("Linha do arquivo --> %s\n", linhaDoArquivo);   
    }

    fclose(arquivo);
    system("pause");
}