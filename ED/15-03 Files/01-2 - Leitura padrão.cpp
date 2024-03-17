#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Parte 2 - Atividade 1
*/

#define MAX 101

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	char string[MAX];
    	FILE *arq;
    	
    	arq = fopen("1.txt", "r"); //Ler o arquivo
    	
    	//Teste pra ver se o arquivo foi aberto
    	if (arq == NULL) {
    		printf("Erro ao abrir o arquivo!");
    		return 0;
		}
		
		//Enquanto tiver valores para serem lidos, a condicional será verdadeira
		while (fgets(string, sizeof(string), arq) != NULL) {
			printf("%s", string);
		}
		
		fclose(arq);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

