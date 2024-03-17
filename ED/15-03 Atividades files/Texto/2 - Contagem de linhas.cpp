#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 2. Faça um programa que receba do usuário um arquivo texto e mostre na tela 
quantas linhas esse arquivo possui.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	char path[100];
    	char ch;
    	int cont = 0;
    	
    	printf("Digite o caminho do arquivo: ");
    	scanf("%s", path);
    	
    	arq = fopen(path, "r");
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo!");
    		return 0;
		}
		
		while ((ch = fgetc(arq)) != EOF) { //Ler até o final do arquivo
			if (ch == '\n') {
				cont++;
			}
		}
		
		fclose(arq);
		printf("O arquivo possui %i linhas\n", cont);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

