#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Faça uma função que receba um valor e verifique se o valor é perfeito ou não. Um
valor é dito perfeito quando ele é igual a soma dos seus divisores excetuando ele
próprio. (Ex: 6 é perfeito, 6 = 1 + 2 + 3, que são seus divisores). A função deve
retornar 1 caso o valor seja perfeito e 0 caso contrário
*/

int perfect_val(int n) {
	int soma = 0;
	
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			soma += i;
		}
	}
	
	if (soma == n) {
		printf("O número é perfeito\n");
		return 1;
	} else {
		printf("O número não é perfeito\n");
		return 0;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	int num;
    	printf("Digite um número: ");
    	scanf("%i", &num);
    	
    	perfect_val(num);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

