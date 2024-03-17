#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	char path[100];
    	char ch, check;
    	int cont = 0;
    	
    	printf("Digite o caminho do arquivo: ");
    	scanf("%s", path);
    	
    	printf("Digite um caractere: ");
    	scanf(" %c", &check);
    	
    	arq = fopen(path, "rb");
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo!");
    		return 0;
		}
		
		while (fread(&ch, sizeof(char), 1, arq)) {
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

