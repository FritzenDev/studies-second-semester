#include <stdio.h>
#include <string.h>
#include <locale.h>

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
    	
    	arq1 = fopen(path1, "rb");
    	if (arq1 == NULL) {
    		printf("Erro ao abrir o arquivo de entrada!");
    		return 0;
		}
		
		arq2 = fopen(path2, "rb");
    	if (arq2 == NULL) {
    		printf("Erro ao abrir o arquivo de saída!");
    		fclose(arq1);
    		return 0;
		}
		
		arq3 = fopen(path3, "wb");
    	if (arq2 == NULL) {
    		printf("Erro ao abrir o arquivo de saída!");
    		fclose(arq1);
    		fclose(arq2);
    		return 0;
		}
		
		// Copiar conteúdo do primeiro arquivo para o terceiro arquivo
    	while (fread(&ch, sizeof(char), 1, arq1)) {
        	fputc(ch, arq3);
    	}
    	
    	// Copiar conteúdo do segundo arquivo para o terceiro arquivo
    	while (fread(&ch, sizeof(char), 1, arq2)) {
        	fputc(ch, arq3);
    	}
    	
    	printf("\nArquivo criado com sucesso. Conteúdo dos arquivos '%s' e '%s' foi concatenado em '%s'.\n", path1, path2, path3);
    	fclose(arq1);
    	fclose(arq2);
    	fclose(arq3);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

