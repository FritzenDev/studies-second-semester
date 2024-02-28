#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Implemente uma função que receba três números reais, ’a’, ’b’ e ’c’, que são os coeficientes de
uma equação do segundo grau e retorne o valor do delta, que é dado por ’b
2 - 4ac’
*/

double num_real(double a, double b, double c) {
	int result = 0;
	result = pow(b, 2) - (4 * a * c);
	return result;
}

int main () {
	char continuar;

	do {
		double n1, n2, n3;
		printf("Digite 3 numeros: ");
		scanf("%lf %lf %lf", &n1, &n2, &n3);
		double resultado = num_real(n1, n2, n3);
		printf("Resultado: %.2lf", resultado);
		scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

