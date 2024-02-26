#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Escreva uma função que receba 3 valores reais X, Y e Z e que verifique se esses
valores podem ser os comprimentos dos lados de um triângulo e, neste caso,
imprime qual o tipo de triângulo formado. Para que X, Y e Z formem um triângulo é
necessário que a seguinte propriedade seja satisfeita: o comprimento de cada lado
de um triângulo é menor do que a soma do comprimento dos outros dois lados. A
função deve identificar o tipo de triângulo formado observando as seguintes
definições:
a) Triângulo Equilátero: os comprimentos dos 3 lados são iguais.
b) Triângulo Isósceles: os comprimentos de 2 lados são iguais.
c) Triângulo Escaleno: os comprimentos dos 3 lados são diferentes.
*/

double tri_verify (double val1, double val2, double val3) {
	double soma1_2 = val1 + val2;
	double soma2_3 = val2 + val3;
	double soma1_3 = val1 + val3;
	if (val1 < soma2_3 && val2 < soma1_3 && val3 < soma1_2) {
		if (val1 == val2 && val1 == val3) {
			printf("Triângulo Equilátero\n");
		} else if ((val1 == val2) || (val2 == val3) || (val1 == val3)) {
			printf("Triângulo Isósceles\n");
		} else if (val1 != val2 && val1 != val3) {
			printf("Triângulo Escaleno\n");
		}
	}
	return 0;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		double x, y, z;
		printf("Digite o X: ");
		scanf("%lf", &x);
		printf("Digite o Y: ");
		scanf("%lf", &y);
		printf("Digite o Z: ");
		scanf("%lf", &z);
		
		tri_verify(x, y, z);

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

