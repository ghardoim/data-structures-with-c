#include <stdlib.h>

#include <stdarg.h> /*
                        Permite que as funções aceitem um número infinito de argumentos.
                        Oferece recursos para percorrer uma lista de argumentos de número e tipo desconhecidos.
                    */
#include <stdio.h>

#define CMD_TAM_MAX 1024

int systemCL(const char* fmt, ...) {
    va_list args;
    char cmd[CMD_TAM_MAX + 1];

    va_start(args, fmt); //String de formatação -- ftm
    vsnprintf(cmd, CMD_TAM_MAX + 1, fmt, args);
    va_end(args);

    return system(cmd);
}

int main() {

    char mensagem[20] = "quinto commit";

    system("git log");
    systemCL("git commit -m \"%s\" --all ", mensagem);

    return 0;
}