#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> //Biblioteca para o tolower

/*
3. Faça um programa que receba do usuário um arquivo texto e mostre na tela 
quantas letras são vogais.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	char path[100];
    	char ch;
    	int cont = 0;
    	
    	printf("Digite o caminho do arquivo: ");
    	scanf("%s", path);
    	
    	arq = fopen(path, "r");
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo!");
    		return 0;
		}
		
		while ((ch = fgetc(arq)) != EOF) { //Ler até o final do arquivo
			ch = tolower(ch); //Garantir que lerá caracteres minúsculos e maiúsculos 
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				cont++;
			}
		}
		
		fclose(arq);
		printf("O arquivo possui %i vogais\n", cont);
    	

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

