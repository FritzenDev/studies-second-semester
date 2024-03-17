#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
4. Declare um array de inteiros e inicialize-o. Em seguida, declare um ponteiro para o 
primeiro elemento do array e imprima os elementos do array usando esse ponteiro.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x[3] = {1, 2, 3}; int *ptrx;
    	
    	ptrx = &x[0];
    	
    	for (int i = 0; i < 3; i++) {
    		printf("%i° Valor: %i\n", i+1, ptrx[i]);
		}

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

