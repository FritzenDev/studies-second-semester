#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
5. Defina uma estrutura chamada Livro que contenha os campos titulo, autor, ano e
preco.
6. Declare um vetor de 5 elementos do tipo Livro e inicialize seus valores.
7. Escreva uma função que receba um vetor de Livro e imprima todos os livros cujo
preço seja maior que 50.
8. Crie uma função que receba um vetor de Livro e retorne o livro mais caro.
9. Implemente uma função que receba um vetor de Livro e retorne o total gasto na
compra de todos os livros.
*/

struct livro {
	char titulo[50];
	char autor[25];
	int ano;
	float price;
};

void maior_50(struct livro fif_price[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		if (fif_price[i].price > 50) {
			printf("\nLivro maior que 50:\n");
			printf("Título: %s\n", fif_price[i].titulo);
		}
	}
}

struct livro maior(struct livro max_price[], int tamanho) {
	float maior = max_price[0].price;
	int index = 0;
	for (int i = 0; i < tamanho; i++) {
		if (max_price[i].price > maior) {
			maior = max_price[i].price;
			index = i;
		}
	}
	return max_price[index];
}

float total_gasto(struct livro total[], int tamanho) {
	float soma = 0;
	for(int i = 0; i < tamanho; i++) {
		soma += total[i].price;
	}
	return soma;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int length;
		printf("Digite quantos livros deseja cadastrar: ");
		scanf("%i", &length);
		getchar();
		struct livro random[length];
		printf("\n");
		for (int i = 0; i < length; i++) {
			printf("%i° Livro:\n", i+1);
			printf("Título: ");
			scanf("%[^\n]", random[i].titulo);
			getchar();
			
			printf("Autor: ");
			scanf("%[^\n]", random[i].autor);
			getchar();
			
			printf("Ano: ");
			scanf("%i", &random[i].ano);
			getchar();
			
			printf("Preço: ");
			fscanf(stdin, "%f", &random[i].price);
			getchar();
			printf("\n");
		}
		
		maior_50(random, length);
		struct livro caro = maior(random, length);
		printf("\nO livro mais caro é %s com preço %.2fR$\n", caro.titulo, caro.price);
		float total = total_gasto(random, length);
		printf("O total gasto na compra de todos os livros é %.2fR$\n", total);

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

