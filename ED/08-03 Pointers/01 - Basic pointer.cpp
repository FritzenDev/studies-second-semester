#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie um programa que declare duas variáveis (inteiro e real) atribua valores para elas e crie dois
ponteiros, cada um apontando para uma destas variáveis. Mostre na tela: O valor e o endereço de
memória das variáveis, o valor do ponteiro, o endereço do ponteiro e o valor apontado pelo
ponteiro. Ao fim diga qual destes valores são iguais? Justifique?
*/

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int x = 5;
		float y = 10.5;
		
		int *ptrx;
		float *ptry;
		
		ptrx = &x;
		ptry = &y;
		
		printf("Valor da variável X: %i\n", x);
		printf("Endereço da variável X: %p\n", &x);
		
		printf("\nValor do ponteiro X: %p\n", ptrx);
		printf("Endereço do ponteiro X: %p\n", &ptrx);
		printf("Valor apontado pelo ponteiro X: %i\n", *ptrx);
		
		printf("\nValor da variável Y: %f\n", y);
		printf("Endereço da variável Y: %p\n", &y);
		
		printf("\nValor do ponteiro Y: %p\n", ptry);
		printf("Endereço do ponteiro Y: %p\n", &ptry);
		printf("Valor apontado pelo ponteiro Y: %f\n", *ptry);
		
		

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

