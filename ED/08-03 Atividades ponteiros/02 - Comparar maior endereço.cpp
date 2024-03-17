#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
3. Escreva um programa que contenha duas variáveis inteiras. Compare seus 
endereços e exiba o maior endereço.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x = 5; int *ptrx;
    	int y = 10; int *ptry;
    	
    	ptrx = &x;
    	ptry = &y;
    	
    	printf("Endereço de X: %p\n", &x);
    	printf("Endereço de Y: %p\n", &y);
    	
    	if (ptrx > ptry) {
    		printf("\nO endereço de X é maior que o de Y\n");
		} else {
			printf("\nO endereço de Y é maior que o de X\n");
		}

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

