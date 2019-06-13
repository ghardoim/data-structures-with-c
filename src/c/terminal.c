#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "../h/terminal.h"

#define CMD_TAM_MAX 1024

int systemCL(const char* fmt, ...) {
    va_list args;
    char cmd[CMD_TAM_MAX + 1];

    va_start(args, fmt); //ftm --> String de formatação.
    vsnprintf(cmd, CMD_TAM_MAX + 1, fmt, args);
    va_end(args);

    return system(cmd);
}