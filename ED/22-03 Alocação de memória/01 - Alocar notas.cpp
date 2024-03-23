#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*
1. Escreva um programa que solicita ao usu�rio a quantidade de alunos de uma turma e aloca um
vetor de notas (n�meros reais). Depois de ler as notas, imprime a m�dia aritm�tica. Obs: n�o deve
ocorrer desperd�cio de mem�ria; e ap�s ser utilizada a mem�ria deve ser devolvida.
*/

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int qtd; float *ptrq;
		
		printf("Digite a quantidade de alunos que a turma possui: ");
		scanf("%i", &qtd);
		
		printf("\n");
		
		ptrq = (float *)malloc(qtd*sizeof(float));
		
		if (ptrq == NULL) {
			printf("Erro: Mem�ria insuficiente!");
			exit(1);
		}
		
		float n1, n2, n3, media;
		float sum = 0;
		float sumT = 0, mediaT;
		
		for (int i = 0; i < qtd; i++) {
			printf("Digite a nota 1 do %i� aluno: ", i+1);
			scanf("%f", &n1);
			
			printf("Digite a nota 2 do %i� aluno: ", i+1);
			scanf("%f", &n2);
			
			printf("Digite a nota 3 do %i� aluno: ", i+1);
			scanf("%f", &n3);
			
			sum = n1 + n2 + n3;
			sumT += sum;
			media = sum / 3;
			mediaT = sumT / qtd;
			ptrq[i] = media;
			printf("\n");
		}
		
		for (int i = 0; i < qtd; i++) {
			printf("\nM�dia do %i� aluno: %.2f", i+1, ptrq[i]);
		}
		printf("\nM�dia da turma: %.2f\n", mediaT);
		
		free(ptrq);
		ptrq = NULL;

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

