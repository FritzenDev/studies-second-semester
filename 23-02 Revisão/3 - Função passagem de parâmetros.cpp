#include <stdio.h>
#include <string.h>

/*
Implemente uma fun��o que recebe como par�metros dois valores inteiros, por meio de passgem
de par�metros, e troque o conte�do deles.
*/

void dois_val(int n1, int n2) {
	printf("\nValor 1: %i\nValor 2: %i", n1, n2);
}

int main () {
	char continuar;

	do {
		printf("\nAntes: ");
		dois_val(1, 2);
		
		printf("\nDepois: ");
		dois_val(3, 4);


	} while (continuar == 'S' || continuar == 's');

	return 0;
}

