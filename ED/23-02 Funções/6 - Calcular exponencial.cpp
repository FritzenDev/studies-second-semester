#include <stdio.h>
#include <string.h>

/*
Faça uma função que receba por parâmetro dois valores X e Z. Calcule e retorne o
resultado de XZ para o programa principal. Atenção não utilize nenhuma função
pronta de exponenciação.
*/

int exp(int x, int z) {
	int calc;
	int xx = x;
	for (int i = 1; i < z; i++) {
		calc = xx * x;
		xx = calc;
	}
	return calc;
}

int main() {
    char continuar;

    do {
    	int x1, z1;
    	printf("Digite o valor de X: ");
		scanf("%i", &x1);
		printf("Digite o valor de Z: ");
		scanf("%i", &z1);
		int result = exp(x1, z1);
		printf("Resultado do calculo exponencial: %i\n", result);
		
    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

