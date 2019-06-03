#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define CMD_TAM_MAX 1024
char cmd[CMD_TAM_MAX + 1];

void teste() {
    FILE *fp;
    int status;
    char conteudo[200]; //define o tamanho do buffer aqui

    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error\n");
        return EXIT_FAILURE; //Manipule os erros
    }

    while (fgets(conteudo, 200, fp) != NULL) //Lendo enquanto é diferente de vazio.

    status = pclose(fp);
    if (status == -1) {
        printf("Error\n");
        return EXIT_FAILURE; //Manipule os erros
    }
    else {
        //aqui pode determinar se houve sucesso ou uma falha na execucao do comando.
    }
}


int systemCL(const char* fmt, ...) {
    va_list args;
    
    va_start(args, fmt); //ftm --> String de formatação.
    vsnprintf(cmd, CMD_TAM_MAX + 1, fmt, args);
    va_end(args);

    return system(cmd);
}


int main() {

    char nome[20] = "Gabriel";
    
    printf("escreve ai: %d\n", systemCL("find . -iname *.csv -print0 | xargs -0 grep \"%s\"", nome));

    return 0;
}