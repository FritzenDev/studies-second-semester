#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie uma função recursiva para calcular a soma 1 + 1/2 + 1/3 + … + 1/n, sendo n >
0.
*/

double soma_desc(int n) {
	if (n == 1) {
		return 1.0;
	} else {
		return 1.0/n + soma_asc(n-1);
	}
}

/*
Exemplo: Quando digitado 3, enquanto não chegar a 1, será adicionado:
1/3 e depois 1/2 ao valor 1, caso for digitado 4, será adicionado 1/4, depois 1/3...
*/

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int num;
		printf("Digite um número: ");
		scanf("%i", &num);
		
		printf("Soma ascendente: %.2lf\n", soma_asc(num));

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

