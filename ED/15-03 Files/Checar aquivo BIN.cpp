#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Checar se o arquivo bin�rio est� com os dados do arquivo TXT
*/

#define MAX 101

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arqB;
    	arqB = fopen("1.bin", "rb"); //R e RB = Apenas leitura
    	
    	if (arqB == NULL) {
    		printf("Erro ao abrir o arquivo bin�rio\n");
    		return 0;
		}
		
		printf("Conte�do do arquivo bin�rio:\n");
		
		char string[MAX];
		while (fgets(string, sizeof(string), arqB) != NULL) {
			printf("%s", string);
		}
		
		fclose(arqB);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

