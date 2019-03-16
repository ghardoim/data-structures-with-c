#include <stdio.h>
#include <stdlib.h>

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

void linha() {
    printf(" _______________________________________________________________________________________________ \n");
}

void espacoEmBranco() {
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t|\n");
}