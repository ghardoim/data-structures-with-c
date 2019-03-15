#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define CMD_TAM_MAX 1024

int systemf(const char * fmt, ... ) {
    va_list args;
    char cmd[CMD_TAM_MAX + 1];

    va_start(args, fmt); //String de formatação -- ftm
    vsnprintf(cmd, CMD_TAM_MAX + 1, fmt, args);
    va_end(args);

    return system(cmd);
}

int main() {

    char mensagem[20] = "terceiro commit";

    system("git log");
    systemf("git commit -m \"%s\" --all ", mensagem);

    return 0;
}