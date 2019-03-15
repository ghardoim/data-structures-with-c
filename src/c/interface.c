#include <stdio.h>
#include <stdlib.h>

#include "../h/lib.h"

void escolhaErrada() {
    system("clear");
    printf(" _______________________________________________________________________________________________ \n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\tEscolha errada\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\tDigite novamente sua escolha.\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf(" _______________________________________________________________________________________________ \n");
    
    system("sleep 5");
}

void telaInicial() {
    system("clear");
    printf(" _______________________________________________________________________________________________ \n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\tSistema de atendimento de pacientes\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t(1) -- Cadastrar Pacientes\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t(2) -- Alterar Dados\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t(3) -- Remover Paciente\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t(4) -- Listar Pacientes\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t(5) -- Encerrar o Programa\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\tDigite sua escolha: ");
}

void entradaDeDados(PACIENTE* novoPaciente){
    system("clear");
    printf(" _______________________________________________________________________________________________ \n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\tInforme os dados do paciente.\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\tNome: ");
    fflush(stdin);
    gets(novoPaciente->individuo.nome);
    fflush(stdin);
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\tIdade: ");
    scanf("%d", &novoPaciente->individuo.idade);
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    novoPaciente->individuo.id = total++;
}

void saidaDeDados(PACIENTE* umPaciente) {
    printf(" _______________________________________________________________________________________________ \n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\tDados do paciente: %s\t\t\t\t|\n", umPaciente->individuo.nome);
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\tIdade: %d\t\t\t\t|\n", umPaciente->individuo.idade);    
}

void ninguemCadastrado() {
    printf(" _______________________________________________________________________________________________ \n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\tSem pacientes cadastrados.\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf(" _______________________________________________________________________________________________ \n\n\n");
    
}

void problemaComArquivo() {
    system("clear");
    printf(" _______________________________________________________________________________________________ \n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\tProblema ao acessar o banco de dados.\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf(" _______________________________________________________________________________________________ \n");
    system("sleep 5");
}