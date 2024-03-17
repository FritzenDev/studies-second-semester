#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 1. Declare um ponteiro para um inteiro e atribua a ele o endere�o de uma vari�vel 
inteira. 

2. Escreva um programa que declare um inteiro, um float e um char, e ponteiros para 
inteiro, float, e char. Associe as vari�veis aos ponteiros (use &). Modifique os 
valores de cada vari�vel usando os ponteiros. Imprima os valores das vari�veis 
antes e ap�s a  modifica��o.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x = 5; int *ptrx;
    	float y = 3.10; float *ptry;
    	char z = 'A'; char *ptrz;
    	
    	ptrx = &x;
    	ptry = &y;
    	ptrz = &z;
    	
    	printf("Vari�veis antes da modifica��o:\n");
    	printf("X: %i\n", x);
    	printf("Y: %.2f\n", y);
    	printf("Z: %c\n", z);
    	
    	*ptrx = 10;
    	*ptry = 6.20;
    	*ptrz = 'B';
    	
    	printf("\nVari�veis depois da modifica��o:\n");
    	printf("X: %i\n", x);
    	printf("Y: %.2f\n", y);
    	printf("Z: %c\n", z);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

