#include <stdio.h>
#include <string.h>

/*
Faça uma função que lê 50 valores inteiros e retorna o maior deles.
*/

#define length 50

int maior_num(int array[], int tamanho) {
	int maior = array[0];
	for (int i = 0; i < tamanho; i++) {
		if (array[i] > maior) {
			maior = array[i];
		}
	}
	return maior;
}

int main() {
    char continuar;

    do {
    	int num[length];
    	for (int i = 0; i < length; i++) {
    		printf("Digite o numero %i: ", i+1);
    		scanf("%i", &num[i]);
		}
		int maior = maior_num(num, length);
		printf("O maior valor digitado foi: %i\n", maior);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

