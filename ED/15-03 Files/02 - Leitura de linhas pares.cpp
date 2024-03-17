#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Usando o arquivo de texto produzido no exercício anterior, faça um programa que leia esse arquivo
e imprima na tela apenas as linhas pares do arquivo.
*/

#define MAX 101

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	char string[MAX];
    	FILE *arq;
    	int cont = 1;
    	
    	arq = fopen("1.txt", "r"); //Ler o arquivo
    	
    	//Teste pra ver se o arquivo foi aberto
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo!");
    		return 0;
		}
		
		//Enquanto tiver valores para serem lidos, a condicional será verdadeira
		while (fgets(string, sizeof(string), arq) != NULL) {
			if (cont % 2 == 0) {
				printf("%s", string);
			}
			cont++;
		}
		
		fclose(arq);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

