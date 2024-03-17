#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 10.Faça um programa que permita que o usuário entre com diversos nomes e telefone 
para cadastro, e crie um arquivo com essas informações, uma por linha. O usuário 
finaliza a entrada com ‘0’ para o telefone.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	char nome[50], tel[50];
    	int cont = 0;
    	
    	arq = fopen("cadastro.txt", "w");
    	if (arq == NULL) {
        	printf("Erro ao criar o arquivo.\n");
        	return 0;
    	}
    	
    	printf("Digite os nomes e telefones para cadastro (digite '0' para o telefone para finalizar):\n");

    	while (1) {
        	printf("Nome: ");
        	scanf("%s", nome);
        
        	if (nome[0] == '0')
            	break;

        	printf("Telefone: ");
        	scanf("%s", tel);
        	printf("\n");
        
        	fprintf(arq, "%s - %s\n", nome, tel);
        	cont++;
    	}
    	
    	fclose(arq);
    	printf("\n%i cadastros foram salvos no arquivo 'cadastro.txt'.\n", cont);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}


