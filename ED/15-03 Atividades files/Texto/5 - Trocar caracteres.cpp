#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*
Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo 
texto contendo o texto do arquivo de entrada, mas com as vogais substituídas por 
‘*’.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq1, *arq2;
    	char path1[100], path2[100];
    	char ch;
    	
    	printf("Digite o caminho do arquivo de entrada: ");
    	scanf("%s", path1);
    	
    	printf("Digite o caminho do arquivo de saída: ");
    	scanf("%s", path2);
    	
    	arq1 = fopen(path1, "r");
    	if (arq1 == NULL) {
    		printf("Erro ao abrir o arquivo de entrada!");
    		return 0;
		}
		
		arq2 = fopen(path2, "w");
    	if (arq2 == NULL) {
    		printf("Erro ao abrir o arquivo de saída!");
    		return 0;
		}
		
		while ((ch = fgetc(arq1)) != EOF) {
			ch = tolower(ch);
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				fputc('*', arq2);
			} else {
				fputc(ch, arq2);
			}
		}
		
		printf("Arquivo criado com sucesso!");
		fclose(arq1);
		fclose(arq2);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

