#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
1. Faça um programa que crie um arquivo TEXTO em disco, com o nome “dados.txt”, 
e escreva neste arquivo em disco uma contagem que vá de 1 até 100, com um 
número em cada linha.
*/

#define MAX 3

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	
    	arq = fopen("dados.txt", "w");
    	
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo\n");
    		return 0;
		}
		
		for (int i = 0; i < 100; i++) {
			fprintf(arq, "%i\n", i+1);
		}
		
		printf("Arquivo preenchido de 1 a 100 com sucesso!\n");
		
		fclose(arq);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

