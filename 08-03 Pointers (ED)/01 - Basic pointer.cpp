#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie um programa que declare duas vari�veis (inteiro e real) atribua valores para elas e crie dois
ponteiros, cada um apontando para uma destas vari�veis. Mostre na tela: O valor e o endere�o de
mem�ria das vari�veis, o valor do ponteiro, o endere�o do ponteiro e o valor apontado pelo
ponteiro. Ao fim diga qual destes valores s�o iguais? Justifique?
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
		
		printf("Valor da vari�vel X: %i\n", x);
		printf("Endere�o da vari�vel X: %p\n", &x);
		
		printf("\nValor do ponteiro X: %p\n", ptrx);
		printf("Endere�o do ponteiro X: %p\n", &ptrx);
		printf("Valor apontado pelo ponteiro X: %i\n", *ptrx);
		
		printf("\nValor da vari�vel Y: %f\n", y);
		printf("Endere�o da vari�vel Y: %p\n", &y);
		
		printf("\nValor do ponteiro Y: %p\n", ptry);
		printf("Endere�o do ponteiro Y: %p\n", &ptry);
		printf("Valor apontado pelo ponteiro Y: %f\n", *ptry);
		
		

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

