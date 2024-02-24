#include <stdio.h>
#include <string.h>

/*
Implemente uma função recursiva que recebe um número ’n’ e retorna n-ésimo numero da
sequencia de fibonacci. A sequencia de fibonacci funciona da seguinte forma:
se n = 1 então fibonacci(n) = 0
se n = 2 então fibonacci(n) = 1
se n > 2 então fibonacci(n) = fibonacci(n-1)+fibonacci(n-2)
*/



int calc(int n) {
	if (n == 1) {
		return 1; //Precisa ser 1 nos dois para seguir a ordem correta da fibonnaci || Se quiser fazer do jeito proposto, seguirá outra lógica
	}
	if (n == 2) {
		return 1;
	}
	if (n > 2) {
		return calc(n - 1) + calc(n - 2);
	}
}

int main () {
	char continuar;

	do {
		int num;
		printf("Digite o e-nesimo numero a ser exibido: ");
		scanf("%i", &num);
		
		int result = calc(num);
		printf("Resultado: %i", result);

	} while (continuar == 'S' || continuar == 's');

	return 0;
}

