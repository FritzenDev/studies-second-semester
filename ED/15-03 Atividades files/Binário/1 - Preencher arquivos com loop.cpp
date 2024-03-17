#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 3

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	
    	arq = fopen("dados.bin", "wb");
    	
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo\n");
    		return 0;
		}
		
		for (int i = 0; i < 100; i++) {
			fwrite(&i, sizeof(int), 1, arq);
		}
		
		printf("Arquivo preenchido de 1 a 100 com sucesso!\n");
		
		fclose(arq);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

