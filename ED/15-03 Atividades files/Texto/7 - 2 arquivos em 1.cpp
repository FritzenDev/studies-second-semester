#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
7. Fa�a um programa que receba dois arquivos do usu�rio, e crie um terceiro arquivo 
com o conte�do dos dois primeiros juntos (o conte�do do primeiro seguido do 
conte�do do segundo).
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq1, *arq2, *arq3;
    	char path1[100], path2[100], path3[100];
    	char ch;
    	
    	printf("Digite o caminho do primeiro arquivo: ");
    	scanf("%s", path1);
    	
    	printf("\nDigite o caminho do segundo arquivo: ");
    	scanf("%s", path2);
    	
    	printf("\nDigite o caminho do terceiro arquivo: ");
    	scanf("%s", path3);
    	
    	arq1 = fopen(path1, "r");
    	if (arq1 == NULL) {
    		printf("Erro ao abrir o arquivo de entrada!");
    		return 0;
		}
		
		arq2 = fopen(path2, "r");
    	if (arq2 == NULL) {
    		printf("Erro ao abrir o arquivo de sa�da!");
    		fclose(arq1);
    		return 0;
		}
		
		arq3 = fopen(path3, "w");
    	if (arq2 == NULL) {
    		printf("Erro ao abrir o arquivo de sa�da!");
    		fclose(arq1);
    		fclose(arq2);
    		return 0;
		}
		
		// Copiar conte�do do primeiro arquivo para o terceiro arquivo
    	while ((ch = fgetc(arq1)) != EOF) {
        	fputc(ch, arq3);
    	}
    	
    	// Copiar conte�do do segundo arquivo para o terceiro arquivo
    	while ((ch = fgetc(arq2)) != EOF) {
        	fputc(ch, arq3);
    	}
    	
    	printf("\nArquivo criado com sucesso. Conte�do dos arquivos '%s' e '%s' foi concatenado em '%s'.\n", path1, path2, path3);
    	fclose(arq1);
    	fclose(arq2);
    	fclose(arq3);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

