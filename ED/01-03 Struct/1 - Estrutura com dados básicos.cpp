#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie uma struct para armazenar os dados (nome, idade, posi��o, numero_camisa) dos jogadores
de futsal de um time. Crie uma vari�vel para armazenar um determinado �jogador�. Desenvolva um
programa em que o usu�rio consiga entrar com as caracter�sticas de um jogador, armazenando os
valores diretamente na vari�vel �jogador�. Imprima na tela o valor dos atributos da vari�vel �jogador�
depois de ter atribuido valores aos campos.
*/

struct jogador {
	char nome[50];
	int idd;
	char pos[50];
	int num_camisa;
};

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		struct jogador random;
		
		printf("Digite as caracter�sticas do seu jogador:\n");
		printf("Nome: ");
		scanf("%[^\n]", random.nome);
		printf("Idade: ");
		scanf("%i", &random.idd);
		printf("Posi��o: ");
		scanf(" %[^\n]", random.pos);
		printf("N�mero da camisa: ");
		scanf("%i", &random.num_camisa);
		
		printf("\n\nAtributos do jogador:\n\nNome: %s\nIdade: %i\nPosi��o: %s\nN�mero da camisa: %i", random.nome, random.idd, random.pos, random.num_camisa);

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}
