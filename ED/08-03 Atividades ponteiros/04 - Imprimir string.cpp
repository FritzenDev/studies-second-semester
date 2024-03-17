#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
5. Declare uma string (array de caracteres) e inicialize-a. Em seguida, declare um 
ponteiro para o primeiro caractere da string e imprima os caracteres da string 
usando esse ponteiro.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	char string[10] = {"Teste"}; char *ptrs;
		
		ptrs = &string[0];
		
		printf("Elemento da string: %s", ptrs);
		

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

