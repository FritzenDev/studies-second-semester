#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
9. Declare um array de inteiros e inicialize-o. Declare um ponteiro para o primeiro 
elemento do array e um ponteiro para o último elemento do array. Imprima o 
primeiro e o último elemento do array usando esses ponteiros.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x[3] = {2, 3, 4}; int *ptrx;
    	ptrx = &x[0];
    	
    	int *ptrx1;
    	ptrx1 = &x[2];
    	
    	printf("Primeiro elemento do array: %i\n", *ptrx);
    	printf("Último elemento do array: %i\n", *ptrx1);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

