#ifndef _LIB_H_
#define _LIB_H_

typedef struct data {
    int ano, mes, dia;
}DATA;

typedef struct pessoa {
    DATA dataNascimento;
    float peso, altura;
    char nome[20];
    int idade, id;
}PESSOA;


typedef struct paciente {
    struct paciente *pacienteAntes, *pacienteDepois;
    PESSOA individuo;
}PACIENTE;

int opcao, total;

void cadastrar(PACIENTE** primeiro, PACIENTE** ultimo);
void alterar(PACIENTE* primeiro, PACIENTE* ultimo);
void remover(PACIENTE** primeiro, PACIENTE** ultimo);
void exibir(PACIENTE* primeiro, PACIENTE* ultimo);

void escreveNoArquivo(PACIENTE* umPaciente);
void entradaDeDados(PACIENTE* novoPaciente);
void saidaDeDados(PACIENTE* umPaciente);
void lerDoArquivo();

void telaInicial();
void escolhaErrada();
void ninguemCadastrado();
void problemaComArquivo();

#endif