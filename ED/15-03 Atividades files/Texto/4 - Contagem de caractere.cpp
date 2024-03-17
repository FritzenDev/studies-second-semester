#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*
 4. Faça um programa que receba do usuário um arquivo texto e um caracter. Mostre 
na tela quantas vezes aquele caractere ocorre dentro do arquivo.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	char path[100];
    	char ch;
    	int cont = 0;
    	char check;
    	
    	printf("Digite o caminho do arquivo: ");
    	scanf("%s", path);
    	
    	printf("Digite um caractere: ");
    	scanf(" %c", &check);
    	
    	arq = fopen(path, "r");
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo!");
    		return 0;
		}
		
		while ((ch = fgetc(arq)) != EOF) {
			ch = tolower(ch);
			if(ch == check) {
				cont++;
			}
		}
		
		fclose(arq);
		printf("\nO caractere '%c' ocorre %i vezes em '%s'\n", check, cont, path);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

