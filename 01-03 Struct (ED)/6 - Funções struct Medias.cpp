#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
16. Defina uma estrutura Aluno que contenha os campos nome, matricula, nota1,
nota2 e nota3.
17.Escreva uma função que calcule a média das notas de um aluno.
18.Implemente uma função que receba um vetor de alunos e retorne o aluno com a
maior média.
19.Crie uma função que receba um vetor de alunos e retorne a média da turma.
*/

#define MAX_ALUNOS 50

struct Aluno {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
};

float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

struct Aluno alunoMaiorMedia(struct Aluno alunos[], int numAlunos) {
    struct Aluno alunoMaior = alunos[0];
    float maiorMedia = calcularMedia(alunos[0]);
    
    for (int i = 1; i < numAlunos; i++) {
        float media = calcularMedia(alunos[i]);
        if (media > maiorMedia) {
            maiorMedia = media;
            alunoMaior = alunos[i];
        }
    }
    
    return alunoMaior;
}

float mediaTurma(struct Aluno alunos[], int numAlunos) {
    float somaNotas = 0;
    
    for (int i = 0; i < numAlunos; i++) {
        somaNotas += calcularMedia(alunos[i]);
    }
    
    return somaNotas / numAlunos;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	struct Aluno alunos[MAX_ALUNOS];
    	int numAlunos;
    
    	printf("Digite o número de alunos na turma: ");
    	scanf("%i", &numAlunos);
    
    	if (numAlunos > MAX_ALUNOS) {
        	printf("O número de alunos excede o limite máximo!\n");
        	return 1;
    	}
    
    	for (int i = 0; i < numAlunos; i++) {
        	printf("Digite o nome do aluno %d: ", i+1);
        	scanf(" %[^\n]", alunos[i].nome);
        
        	printf("Digite a matrícula do aluno %d: ", i+1);
        	scanf("%i", &alunos[i].matricula);
        
        	printf("Digite a nota 1 do aluno %d: ", i+1);
        	scanf("%f", &alunos[i].nota1);
        
        	printf("Digite a nota 2 do aluno %d: ", i+1);
        	scanf("%f", &alunos[i].nota2);
        
        	printf("Digite a nota 3 do aluno %d: ", i+1);
        	scanf("%f", &alunos[i].nota3);
        	printf("\n");
    	}
    
    	struct Aluno alunoMaior = alunoMaiorMedia(alunos, numAlunos);
    	printf("\nO aluno com maior média é:\n");
    	printf("Nome: %s\n", alunoMaior.nome);
    	printf("Matrícula: %i\n", alunoMaior.matricula);
    	printf("Média: %.2f\n", calcularMedia(alunoMaior));
    
    	printf("\nA média da turma é: %.2f\n", mediaTurma(alunos, numAlunos));

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

