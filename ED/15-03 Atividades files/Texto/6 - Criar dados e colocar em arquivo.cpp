#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
6. Faça um programa que leia (do teclado) um cadastro de 10 alunos, indicando o 
nome, nota1, nota2. Calcule a média aritmética simples dos 10 alunos e depois 
escreva em um arquivo texto os dados de cada aluno: nome, nota1, nota2 e média. 
Lembre-se de que as notas e média deverão ser apresentadas como valores que 
possuem até 2 casas após a vírgula.
*/

#define MAX 3 // Só mudar por 10

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
        
        arq = fopen("alunos.txt", "w");
        if (arq == NULL) {
        	printf("Erro ao criar o arquivo.\n");
        	return 0;
		}
		
		fprintf(arq, "Nome\tNota1\tNota2\tMédia\n");
		for (int i = 0; i < MAX; i++) {
			fprintf(arq, "%s\t%.2f\t%.2f\t%.2f\n", alunos[i].name, alunos[i].n1, alunos[i].n2, alunos[i].media);
		}
		
		fprintf(arq, "\nMédia da turma: %.2f\n", media_turma);
		
		fclose(arq);
		
		printf("\nOs dados dos alunos foram salvos em 'alunos.txt'\n");

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

