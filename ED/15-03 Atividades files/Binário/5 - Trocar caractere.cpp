#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

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
    	
    	arq1 = fopen(path1, "rb");
    	if (arq1 == NULL) {
    		printf("Erro ao abrir o arquivo de entrada!");
    		return 0;
		}
		
		arq2 = fopen(path2, "wb");
    	if (arq2 == NULL) {
    		printf("Erro ao abrir o arquivo de saída!");
    		return 0;
		}
		
		while (fread(&ch, sizeof(char), 1, arq1)) {
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

