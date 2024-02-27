#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Fa�a uma fun��o que recebe por par�metro o raio de um c�rculo e calcule e retorne
a �rea do c�rculo.
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

