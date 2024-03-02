#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie uma struct para armazenar os dados (nome, idade, posição, numero_camisa) dos jogadores
de futsal de um time. Crie uma variável para armazenar um determinado ’jogador’. Desenvolva um
programa em que o usuário consiga entrar com as características de um jogador, armazenando os
valores diretamente na variável ’jogador’. Imprima na tela o valor dos atributos da variável ’jogador’
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
		
		printf("Digite as características do seu jogador:\n");
		printf("Nome: ");
		scanf("%[^\n]", random.nome);
		printf("Idade: ");
		scanf("%i", &random.idd);
		printf("Posição: ");
		scanf(" %[^\n]", random.pos);
		printf("Número da camisa: ");
		scanf("%i", &random.num_camisa);
		
		printf("\n\nAtributos do jogador:\n\nNome: %s\nIdade: %i\nPosição: %s\nNúmero da camisa: %i", random.nome, random.idd, random.pos, random.num_camisa);

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}
