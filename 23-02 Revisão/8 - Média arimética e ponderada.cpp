#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Escreva uma função que recebe as 3 notas de um aluno por parâmetro e uma
letra. Se a letra for A o procedimento calcula a média aritmética das notas do aluno
e se for P, a sua média ponderada (pesos: 5, 3 e 2).
*/

float calc_media(float n1, float n2, float n3, char ap) {
	float calcA, calcP;
	if (ap == 'A') {
		calcA = (n1 + n2 + n3) / 3;
		printf("Resultado da média A: %.2f", calcA);
	} else if (ap == 'P') {
		calcP = ((n1 * 5) + (n2 * 3) + (n3 * 2)) / 10;
		printf("Resultado da média P: %.2f", calcP);
	}
	return 0;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		char a;
		float nota1, nota2, nota3;
		
		printf("Digite as 3 notas do aluno: \n");
		scanf("%f", &nota1);
		scanf("%f", &nota2);
		scanf("%f", &nota3);
		
		printf("Digite a média que deseja tirar (A ou P): ");
		scanf("%s", &a);
		
		calc_media(nota1, nota2, nota3, a);

		scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

