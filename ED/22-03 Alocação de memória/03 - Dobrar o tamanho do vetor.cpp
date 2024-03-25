#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*
3. Escreva um programa que tenha inicialmente um vetor de 10 posições, onde o usuário pode inserir
valores neste vetor quantas vezes ele quiser e quando ele decidir parar, os valores armazenados
no vetor devem ser impressos. Sempre que o vetor estiver com mais de 70% das posições
preenchidas, ele deve dobrar de tamanho. Dica: Faça um menu para o usuário poder escolher se
inseri um novo elemento ou finaliza a computação.
*/

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int *x;
		x = (int *)malloc(10 * sizeof(int));
		int length = 10;
		int size = 0;
		int choice, value;
		
		while (1) {
			printf("1. Inserir valor\n");
			printf("2. Finalizar\n");
			printf("Escolha uma opção: ");
			scanf("%i", &choice);
			printf("\n");
			switch (choice) {
				case 1:
					if (size >= length * 0.7) {
						length *= 2;
						x = (int *)realloc(x, length * sizeof(int));
					}
					printf("Insira um valor: ");
					scanf("%i", &value);
					x[size++] = value;
					printf("\n");
					break;
				case 2:
					printf("Números digitados:\n");
					for (int i = 0; i < size; i++) {
						printf("%i ", x[i]);
					}
					printf("\n");
					free(x);
					return 0;
				default:
					printf("Opção inválida\n");
			}
		}

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

