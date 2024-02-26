#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Escreva uma fun��o recursiva em C para calcular a pot�ncia de um n�mero inteiro
positivo.
*/

int potencia(int base, int exp) {
	if (exp == 0) {
		return 1;
	} else {
		return base * potencia(base, exp - 1); 
		/*Ex: 5^3 = base(5) (3-1 = 2) * base(5) (2-1 = 1) * base(5) (1-1 = 0), termina quando exp chegar a 0
		ocasionando o fim da fun��o*/
	}
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int x, y;
		printf("Digite a base: ");
		scanf("%i", &x);
		printf("Digite o expoente: ");
		scanf("%i", &y);

		printf("Resultado de %i elevado a %i �: %i\n", x, y, potencia(x, y));

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

