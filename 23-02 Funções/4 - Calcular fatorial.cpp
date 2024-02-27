#include <stdio.h>
#include <string.h>

/*
Faça uma função que receba um valor inteiro e positivo e calcula o seu fatorial. Ao
final da função o resultado deve ser impresso na tela.
*/

int fat(int N){
	if(N == 0){
		return 1;
	}else{
		return N * fat(N-1);
	}
}

int main() {
    char continuar;

    do {
    	int num;
    	printf("Digite um numero para calcular seu fatorial: ");
    	scanf("%i", &num);
    	
    	printf("Resultado de %i!: %i\n", num, fat(num));

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

