#include <conio.h>
#include <stdio.h>

#include "../h/help.h"

void get(char string[]) {
    fflush(stdin);
    int i = 0;
    do {   
        string[i] = getch();          
        if(string[i] == 0x08 && i > 0) { //Backspace
            printf("\b \b"); 
            string[i] = 0x00;
            i--;

        } else if (string[i] == 13) { // Enter  
            string[i] = 0x00;
            break;

        } else if (string[i] != 0x08){
            putchar(string[i]);
            i++;              
        }
    }while(i < 50);
}