#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 6. Crie um programa que contenha um array de inteiros contendo 5 elementos. 
Utilizando apenas aritmética de ponteiros, leia esse vetor do teclado e imprima o 
dobro de cada valor lido.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x[5]; int *ptrx;
    	
    	ptrx = &x[0];
    	
    	for (int i = 0; i < 5; i++) {
    		printf("Digite o %i° valor: ", i+1);
    		scanf("%i", ptrx+i);
		}
		
		printf("\nDobro de cada valor digitado:\n");
		for (int i = 0; i < 5; i++) {
			printf("%i°: %i\n", i+1, *(ptrx+i) * 2);
		}
    	

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

