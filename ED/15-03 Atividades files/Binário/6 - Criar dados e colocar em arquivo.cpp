#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 10

struct aluno {
	char name[50];
	float n1;
	float n2;
	float media;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	FILE *arq;
    	struct aluno alunos[MAX];
    	float soma = 0;
    	
    	printf("Digite os dados dos alunos:\n");
        for (int i = 0; i < MAX; i++) {
            printf("Aluno %i:\n", i + 1);
            printf("Nome: ");
            scanf("%s", alunos[i].name);
            printf("Nota 1: ");
            scanf("%f", &alunos[i].n1);
            printf("Nota 2: ");
            scanf("%f", &alunos[i].n2);
            
            printf("\n");
            
            alunos[i].media = (alunos[i].n1 + alunos[i].n2) / 2;
            soma += alunos[i].media;
        }
        
        float media_turma = soma / MAX;
        
        arq = fopen("alunos.bin", "wb");
        if (arq == NULL) {
        	printf("Erro ao criar o arquivo.\n");
        	return 0;
		}
		
		for (int i = 0; i < MAX; i++) {
			fwrite(&alunos[i], sizeof(struct aluno), 1, arq);
		}
		
		fprintf(arq, "\nMédia da turma: %.2f\n", media_turma);
		
		fclose(arq);
		
		printf("\nOs dados dos alunos foram salvos em 'alunos.bin'\n");

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

