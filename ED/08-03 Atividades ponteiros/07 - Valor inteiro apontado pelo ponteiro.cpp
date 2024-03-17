#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 8. Declare duas variáveis inteiras e atribua valores a elas. Declare dois ponteiros para 
inteiros e atribua os endereços das variáveis aos ponteiros. Em seguida, imprima 
os valores das variáveis usando os ponteiros.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int x = 5; int *ptrx;
    	int y = 10; int *ptry;
    	
    	ptrx = &x;
    	ptry = &y;
    	
    	printf("Valor de X usando ponteiro: %i\n", *ptrx);
    	printf("Valor de X usando ponteiro: %i\n", *ptry);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

