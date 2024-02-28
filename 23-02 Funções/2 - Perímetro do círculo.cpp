#include <stdio.h>
#include <string.h>

/*
Faça uma função que recebe por parâmetro o raio de um círculo e calcule e retorne
a perímetro do círculo.
*/

float calc_perimetro(int num) {
	return 2 * 3.14 * num;
}

int main () {
	char continuar;

	do {
		int raio;
		
		printf("Digite o raio do circulo: ");
		scanf("%i", &raio);
		
		float result = calc_perimetro(raio);
		
		printf("Resultado: %.2f", result);
		scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}
