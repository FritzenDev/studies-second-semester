#include <stdio.h>
#include <string.h>

/*
Fa�a uma fun��o que recebe por par�metro o raio de um c�rculo e calcule e retorne
a per�metro do c�rculo.
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

	} while (continuar == 'S' || continuar == 's');

	return 0;
}
