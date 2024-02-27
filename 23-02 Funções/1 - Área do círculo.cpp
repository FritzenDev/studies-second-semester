#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Faça uma função que recebe por parâmetro o raio de um círculo e calcule e retorne
a área do círculo.
*/

float calc_area(int num) {
	return pow(num, 2) * 3.14159;
}

int main () {
	char continuar;

	do {
		int raio;
		
		printf("Digite o raio do circulo: ");
		scanf("%i", &raio);
		
		float result = calc_area(raio);
		
		printf("Resultado: %.2f", result);

	} while (continuar == 'S' || continuar == 's');

	return 0;
}

