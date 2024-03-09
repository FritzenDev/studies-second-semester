#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie um programa que contenha um vetor de inteiros contendo 5 elementos. Utilizando apenas
aritmética de ponteiros, leia esse vetor do teclado e imprima o dobro de cada valor lido.
*/

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int x[5];
		int *p;
		
		p = &x[0];
		
		for (int i = 0; i < 5; i++) {
			printf("Digite o %i° valor: ", i+1);
			scanf("%i", p+i);
		}
		printf("\n");
		for (int i = 0; i < 5; i++) {
			printf("%i° Valor dobrado: %i\n", i+1, *(p + i) * 2);
		}

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

