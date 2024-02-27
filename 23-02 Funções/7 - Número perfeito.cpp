#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Fa�a uma fun��o que receba um valor e verifique se o valor � perfeito ou n�o. Um
valor � dito perfeito quando ele � igual a soma dos seus divisores excetuando ele
pr�prio. (Ex: 6 � perfeito, 6 = 1 + 2 + 3, que s�o seus divisores). A fun��o deve
retornar 1 caso o valor seja perfeito e 0 caso contr�rio
*/

int perfect_val(int n) {
	int soma = 0;
	
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			soma += i;
		}
	}
	
	if (soma == n) {
		printf("O n�mero � perfeito\n");
		return 1;
	} else {
		printf("O n�mero n�o � perfeito\n");
		return 0;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int num;
    	printf("Digite um n�mero: ");
    	scanf("%i", &num);
    	
    	perfect_val(num);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

