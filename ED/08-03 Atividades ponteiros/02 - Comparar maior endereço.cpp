#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
3. Escreva um programa que contenha duas vari�veis inteiras. Compare seus 
endere�os e exiba o maior endere�o.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x = 5; int *ptrx;
    	int y = 10; int *ptry;
    	
    	ptrx = &x;
    	ptry = &y;
    	
    	printf("Endere�o de X: %p\n", &x);
    	printf("Endere�o de Y: %p\n", &y);
    	
    	if (ptrx > ptry) {
    		printf("\nO endere�o de X � maior que o de Y\n");
		} else {
			printf("\nO endere�o de Y � maior que o de X\n");
		}

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

