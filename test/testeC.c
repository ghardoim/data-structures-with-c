#include <stdio.h>
#include <string.h>

int main() {

    char csv[100] = "uma;linha;de;arquivo;csv";

    printf(" %s ", strtok(csv, ";"));
    printf(" %s ", strtok(NULL, ";"));
    printf(" %s ", strtok(NULL, ";"));
    printf(" %s ", strtok(NULL, ";"));
    printf(" %s ", strtok(NULL, ";"));
    

    return 0;
}