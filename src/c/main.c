#include <stdio.h>
#include <stdlib.h>

#include "../h/terminal.h"
#include "../h/mainLib.h"
#include "../h/arquivo.h"

PACIENTE *firstPaciente = NULL, *lastPaciente = NULL;

/*

    Estrutura de dados: Fila.
    Característica: FIFO (First IN, First OUT) / Primeiro a sair, primeiro a entrar.
    Implementação: Lista Duplamente Ligada.
    Inserção: Final.
    Remoçao: Ínicio. 

*/

void cadastrar(PACIENTE** primeiro, PACIENTE** ultimo) {

    PACIENTE *novo = (PACIENTE*) malloc(sizeof(PACIENTE));

    if (*primeiro == NULL && *ultimo ==NULL) {
        *primeiro = novo;
        novo->pacienteAntes = NULL;   
    } else {
        novo->pacienteAntes = *ultimo;
        (*ultimo)->pacienteDepois = novo;
    }
    *ultimo = novo;
    novo->pacienteDepois = NULL;

    escreveNoArquivo(novo);
    system("pause");
}

void alterar(PACIENTE* primeiro, PACIENTE* ultimo) {
    if (primeiro == NULL && ultimo == NULL);
}

void remover(PACIENTE** primeiro, PACIENTE** ultimo) {
    if (primeiro == NULL && ultimo == NULL);
    if (*primeiro == *ultimo) {
        *primeiro = NULL;
        *ultimo = NULL;
    } else {
        *primeiro = (*primeiro)->pacienteDepois;
    }
    total--;
}

void exibir(PACIENTE* primeiro, PACIENTE* ultimo) {
    system("clear");
    if (primeiro == NULL && ultimo == NULL);
    while (primeiro != NULL && ultimo != NULL){
        if (primeiro->pacienteDepois == NULL) break;
        primeiro = primeiro->pacienteDepois;
    }
    system("pause");    
}

int main() {
    do {
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar(&firstPaciente, &lastPaciente);
                break;
            case 2:
                alterar(firstPaciente, lastPaciente);
                break;
            case 3:
                remover(&firstPaciente, &lastPaciente);
                break;
            case 4:
                //lerDoArquivo();
                exibir(firstPaciente, lastPaciente);
                break;
            case 5:
                //Encerrar.
                break;
            default:
                break;
        }
    } while (opcao != 5);
    return 0;
}
