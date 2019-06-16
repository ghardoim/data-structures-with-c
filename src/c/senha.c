#include <conio.h>
#include <stdio.h>

#include "../h/senha.h"

void esconde(char senha[]) {
    fflush(stdin);
    int i = 0;
    do {   
        senha[i] = getch();          
        if(senha[i] == 0x08 && i > 0) { //Backspace
            printf("\b \b"); 
            senha[i] = 0x00;
            i--;
        } else if (senha[i] == 13) { // Enter  
            senha[i] = 0x00;
            break;
        } else if (senha[i] != 0x08) {
            putchar('*');
            i++;              
        }
    } while (i < 50);
}

void criptografa(char senha[]) {
    int i = 0;
    while (senha[i] != '\0') {
        senha[i] = senha[i] + 1;
        i++;
    }
}