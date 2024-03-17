#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
Crie uma struct para armazenar uma data (dia, mês e ano) . Crie uma variável para armazenar
uma determinada ‘data’ e um ponteiro ’pdata’, que aponta para essa variável. Desenvolva um
programa em que o usuário consiga entrar com uma ‘data’, armazenando os valores diretamente
na variável data, e após isso troque a data para dois anos, três meses e 15 dias depois, por meio
do ponteiro ’pdata’. Imprima na tela o valor dos atributos da variável ’data’ antes e depois de
modificar os valores pelo ponteiro.
*/

struct data {
	int dia;
	int mes;
	int ano;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	struct data x;
    	struct data *pdata;
    	
    	pdata = &x;
    	
    	printf("Digite uma data:\n");
    	printf("Ano: ");
    	scanf("%i", &x.ano);
    	printf("Mês: ");
    	scanf("%i", &x.mes);
    	printf("Dia: ");
    	scanf("%i", &x.dia);
    	
    	printf("\nData digitada pelo usuário:\n");
    	printf("Ano: %i\n", pdata->ano);
    	printf("Mês: %i\n", pdata->mes);
    	printf("Dia: %i\n", pdata->dia);
    	
    	pdata-> ano += 2;
    	pdata-> mes += 3;
    	pdata-> dia += 15;
    	
    	if (x.dia > 30 && x.mes > 12) { //Condicional para checar a veracidade da data
    		x.ano++;
    		x.mes++;
		} else if (x.dia > 30) {
			x.mes++;
			x.dia = x.dia - 30;
		} else if (x.mes > 12) {
			x.ano++;
		}
		
		printf("\nData modificada pelo ponteiro (+2 anos, +3 meses, +15 dias):\n");
    	printf("Ano: %i\n", x.ano);
    	printf("Mês: %i\n", x.mes);
    	printf("Dia: %i\n", x.dia);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

