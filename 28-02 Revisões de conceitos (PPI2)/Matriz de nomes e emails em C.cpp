#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Faça uma matriz ou dois vetores string para armazenar 5 nomes e e-mails
use um loop para imprimir os nomes e e-mails um abaixo do outro
*/

#define length 5

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		char matriz_nome[length][31];
		char matriz_email[length][51];
		//Obtenção dos nomes
		printf("Digite 5 nomes:\n\n");
		for (int i = 0; i < length; i++) {
			printf("Digite o email da %i° pessoa: ", i+1);
			gets(matriz_nome[i]);
		}
		//Obtenção dos emails
		printf("\nDigite 5 emails:\n\n");
		for (int i = 0; i < length; i++) {
			printf("Digite o email da %i° pessoa: ", i+1);
			gets(matriz_email[i]);
		}
		//Impressão dos nomes e emails
		printf("\nLista:\n");
		for (int i = 0; i < length; i++) {
			printf("%i° Nome: %s\n", i+1, matriz_nome[i]);
			printf("%i° Email: %s\n", i+1, matriz_email[i]);
			printf("\n");
		}
		
		scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}


