#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Usando o arquivo de texto produzido no exercício 1, faça um programa que transforme o arquivo de
texto em um arquivo binário.
*/

#define MAX 101

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	char string[MAX];
    	FILE *arqT, *arqB;
    	
    	arqT = fopen("1.txt", "r");
        arqB = fopen("1.bin", "wb");

        if (arqT == NULL || arqB == NULL) {
            printf("Erro ao abrir o arquivo\n");
            return 0;
        }
		
		printf("Transformando arquivo de texto em arquivo binário...\n");
		
		while (fgets(string, sizeof(string), arqT) != NULL) {
			fwrite(string, sizeof(char), strlen(string), arqB);
		}
		
		printf("Arquivo binário criado com sucesso!\n");
    	
    	fclose(arqT);
    	fclose(arqB);
		
    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

