#ifndef _MAINLIB_H_
#define _MAINLIB_H_

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

// Funções da lista duplamente encadeada.
void cadastrar(PACIENTE** primeiro, PACIENTE** ultimo);
void alterar(PACIENTE* primeiro, PACIENTE* ultimo);
void remover(PACIENTE** primeiro, PACIENTE** ultimo);
void exibir(PACIENTE* primeiro, PACIENTE* ultimo);

// Funções com linha de comando.
void commitDoPaciente(PACIENTE* umPaciente);

#endif