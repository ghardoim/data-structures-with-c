#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* arquivo = fopen("resources/pacientes.csv", "r+");
    
    if (arquivo == 0) printf("problema com o arquivo.");
    
    char linha[20];

    fscanf(arquivo, "%s", linha);
    printf("%s", linha);
    
    fclose(arquivo);
    return 0;
}