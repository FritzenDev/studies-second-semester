#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Declare uma vari�vel de tipo char e inicialize-a com um caractere. Em seguida, 
declare um ponteiro para essa vari�vel e imprima o valor do caractere usando o 
ponteiro.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	char x = 'A'; char *ptrx;
    	
    	ptrx = &x;
    	
    	printf("Caractere apontado pelo ponteiro: %c\n", *ptrx);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

