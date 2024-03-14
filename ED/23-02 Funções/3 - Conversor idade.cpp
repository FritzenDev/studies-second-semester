#include <stdio.h>
#include <string.h>

/*
Faça uma função que recebe a idade de uma pessoa em anos, meses e dias e
retorna essa idade expressa em dias.
*/

int calc_idd(int y, int m, int d) {
	int years, months;
	years = y * 365; // 1 ano = 365 dias
	months = m * 30; // 1 mês = 30 dias
	int result = years + months + d; // Soma as conversões
	return result;
}

// Contrário:
// anos = iddD / 365;
//	iddD = iddD % 365;
//	meses = iddD / 30;
//	dias = iddD % 30;
//printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n", anos, meses, dias);

int main() {
    char continuar;

    do {
    	int anos, meses, dias;
    	printf("Digite quantos anos, meses e dias voce tem de vida: ");
    	printf("\nAnos: ");
    	scanf("%i", &anos);
    	printf("Meses: ");
    	scanf("%i", &meses);
    	printf("Dias: ");
    	scanf("%i", &dias);
    	
    	int resultado = calc_idd(anos, meses, dias);
    	printf("Idade convertida em dias: %i", resultado);
    	
    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

