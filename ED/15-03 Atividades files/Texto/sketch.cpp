#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Gere, linha por linha, um arquivo de texto com o seu conteúdo digitado pelo usuário durante a
execução. A gravação do arquivo de ser parada quando o usuário digitar FIM. Apresente, ao final
do processamento, o total de linhas gravadas, no arquivo.
*/

#define MAX 101

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	char string[MAX];
    	FILE *arq;
    	
    	arq = fopen("sketchIN.txt", "w");
    	
    	if (arq == NULL) {
			printf("Erro ao abrir o arquivo\n");
			return 0;
		}
		
		printf("Digite linha por linha, se quiser terminar, digite FIM:\n");
		scanf("%[^\n]", string);
		
		while(strcmp(string, "FIM")){
			fputs(string, arq);
			fputc('\n', arq);
			
			printf("\nDigite linha por linha, se quiser terminar, digite FIM:\n");
			scanf(" %[^\n]", string);
		}
		
		fclose(arq);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

