#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
1. Crie uma estrutura chamada Pessoa que contenha os campos nome, idade e
altura.
2. Declare uma variável do tipo Pessoa e atribua valores aos seus campos.
3. Escreva uma função que receba uma variável do tipo Pessoa como parâmetro e
imprima seus dados.
4. Crie uma função que receba um vetor de Pessoa e retorne a média das idades.
*/

//1
struct pessoa {
	char nome[50];
	int idd;
	float altura;
};

//3
void dados(struct pessoa random) {
	printf("\nNome: %s\n", random.nome);
	printf("Idade: %i\n", random.idd);
	printf("Altura: %.2fM\n", random.altura);
}

//4
float media(struct pessoa med[], int tamanho) {
	int soma = 0;
	for(int i = 0; i < tamanho; i++) {
		soma += med[i].idd;
	}
	float result = (float)soma / tamanho;
	return result;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int length;
		printf("Quantas pessoas você deseja digitar: ");
		scanf("%i", &length);
		//2
		struct pessoa randomm[length];
		
		for (int i = 0; i < length; i++) {
			printf("\n%i° Pessoa:\n", i+1);
			printf("Nome: ");
			scanf(" %[^\n]", randomm[i].nome);
			
			printf("Idade: ");
			scanf("%i", &randomm[i].idd);
			
			printf("Altura: ");
			scanf("%f", &randomm[i].altura);
		}
		printf("\n\n");
		printf("Dados impressos:\n");
		for (int i = 0; i < length; i++) {
			printf("\n%i° Pessoa:", i+1);
			dados(randomm[i]);
		}
		printf("\nMédia de todas as idades: %.2f", media(randomm, length));
	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

