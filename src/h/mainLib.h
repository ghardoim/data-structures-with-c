#ifndef _MAINLIB_H_
#define _MAINLIB_H_

#define IMC(altura, peso) (altura * altura / peso)
#define IDADE(anoNasc) (2019 - anoNasc)

typedef struct data {
    int ano, mes, dia;
}DATA;

typedef struct pessoa {
    DATA dataNascimento;
    float peso, altura;
    char nome[30];
}PESSOA;

typedef struct paciente {
    struct paciente *pacienteAntes, *pacienteDepois;
    PESSOA individuo;
    int id;
}PACIENTE;

int opcao, total;

// Funções da lista duplamente encadeada.
void cadastrar(PACIENTE** primeiro, PACIENTE** ultimo);
void alterar(PACIENTE* primeiro, PACIENTE* ultimo);
void remover(PACIENTE** primeiro, PACIENTE** ultimo);
void exibir(PACIENTE* primeiro, PACIENTE* ultimo);

#endif