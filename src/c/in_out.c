#include <stdlib.h>
#include <stdio.h>

#include "../h/mainLib.h"
#include "../h/interface.h"

void entradaDeDados(PACIENTE* novoPaciente){
    system("clear");
    linha();
    espacoEmBranco();
    printf("|\t\t\t\t\tInforme os dados do paciente.\t\t\t\t|\n");
    espacoEmBranco();
    espacoEmBranco();
    printf("|\t\t\t\tNome: ");
    
    fflush(stdin);
    gets(novoPaciente->individuo.nome);
    fflush(stdin);
    
    espacoEmBranco();
    
    printf("|\t\t\t\tIdade: ");
    scanf("%d", &novoPaciente->individuo.idade);
    
    espacoEmBranco();
    
    novoPaciente->individuo.id = total++;
}

void saidaDeDados(PACIENTE* umPaciente) {
    linha();
    espacoEmBranco();
    printf("|\t\t\t\tDados do paciente: %s\t\t\t\t|\n", umPaciente->individuo.nome);
    espacoEmBranco();
    printf("|\t\t\tIdade: %d\t\t\t\t|\n", umPaciente->individuo.idade);    
}
