#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Escreva uma função recursiva em C para calcular a soma dos primeiros N números
naturais. A função recebe como parâmetro o valor de N.
*/

int soma_naturais(int n) {
	if (n == 0) {
		return 0;
	} else {
		return n + soma_naturais(n - 1);
	}
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int num;
		printf("Digite um número natural: ");
		scanf("%i", &num);
		
		printf("A soma dos primeiros %i números naturais é: %i\n", num, soma_naturais(num));

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

