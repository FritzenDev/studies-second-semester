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
			printf("0. Sair\n");
			printf("Escolha uma opção (Quando desejar sair, digite 0): ");
			scanf("%i", &choice);
			printf("\n");
			while (choice == 1) {
				if (size >= length * 0.7) {
						length *= 2;
						x = (int *)realloc(x, length * sizeof(int));
					}		
								
					printf("Insira um valor: ");
					scanf("%i", &value);
					

					if (value == 0) {
						printf("\nNúmeros digitados:\n");
						for (int i = 0; i < size; i++) {
						printf("%i ", x[i]);
						}
						free(x);
						printf("\n\n");
						break;
					} else {
						x[size++] = value; //Colocar depois do check de value == 0 para que 0 não conte nos valores
					} 					
			}
			if (choice == 0) {
				printf("Você saiu sem digitar números\n");
				exit(1);
			} 
		}

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}
