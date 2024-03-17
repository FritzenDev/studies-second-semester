#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	char nome[50], tel[50];
    	int cont = 0;
    	
    	arq = fopen("cadastro.bin", "wb");
    	if (arq == NULL) {
        	printf("Erro ao criar o arquivo.\n");
        	return 0;
    	}
    	
    	printf("Digite os nomes e telefones para cadastro (digite '0' para o telefone para finalizar):\n");

    	while (1) {
        	printf("Nome: ");
        	scanf("%s", nome);
        
        	if (strcmp(nome, "0") == 0)
            	break;
        
        	printf("Telefone: ");
        	scanf("%s", tel);
        
        	fprintf(arq, "%s - %s\n", nome, tel);
    	}

    	fclose(arq);
    	printf("\nCadastro salvo com sucesso em 'cadastro.bin'\n");

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

