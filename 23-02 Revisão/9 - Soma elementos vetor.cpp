#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Fa�a uma fun��o que receba um vetor de inteiros e o n�mero de elementos desse
vetor e calcule e retorne a soma de todos os elementos.
*/

int vet(int n[], int length) {
	int soma;
	
	for (int i = 0; i < length; i++) {
		soma += n[i];
	}
	return soma;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int tamanho;
		int cont = 0;
		printf("Digite quantos n�meros deseja digitar: ");
		scanf("%i", &tamanho);
		
		int num[tamanho];
		
		for (int i = 0; i < tamanho; i++) {
			printf("Digite o %i� n�mero: ", i+1);
			scanf("%i", &num[i]);
			cont++;
		}
		int result = vet(num, tamanho);
		printf("Soma dos elementos do vetor: %i\n", result);

		scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

