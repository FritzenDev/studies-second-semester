#include <stdio.h>
#include <string.h>

/*
Implemente uma função que receba quatro números inteiros e retorne a soma dos três maiores
números, dentre os quatro recebidos.
*/

int soma(int quant) {
	int result = 0;
	int num = 0;
	for (int i = 0; i < quant; i++) {
		printf("Digite o numero %i: ", i+1);
		scanf("%i", &num);
		result += num;
	}
	return result;
}

int main () {
	char continuar;

	do {
		int result = soma(4);
		printf("\nResultado: %i", result);
		
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

