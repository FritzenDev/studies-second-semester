#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
10. Defina uma estrutura Data que contenha os campos dia, mes e ano.
11. Declare uma função que compare duas datas e retorne verdadeiro se a primeira
data for mais recente que a segunda.
12.Escreva uma função que calcule a diferença em anos entre duas datas.
*/

struct data {
	int days, months, years;
};

int compare(struct data d1, struct data d2) {
    if (d1.years > d2.years || (d1.years == d2.years && d1.months > d2.months) || 
        (d1.years == d2.years && d1.months == d2.months && d1.days > d2.days)) {
        return 1;
    } else {
        return 0;
    }
}

float diff(struct data d1, struct data d2) {
    float diffYears;
    diffYears = d1.years - d2.years;
    if (d1.months < d2.months || (d1.months == d2.months && d1.days < d2.days)) {
        diffYears -= 1;
    }
    return diffYears;
}


int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	struct data random[2];
    	for (int i = 0; i < 2; i++) {
    		printf("Digite a %i° data:\n", i+1);
    		printf("\nDias: ");
    		scanf("%i", &random[i].days);
    		
    		printf("Meses: ");
    		scanf("%i", &random[i].months);
    		
    		printf("Anos: ");
    		scanf("%i", &random[i].years);
    		printf("\n");
		}
		
		printf("\n");
		if (compare(random[0], random[1])) {
            printf("A primeira data é mais recente.\n");
        } else {
            printf("A segunda data é mais recente ou as datas são iguais.\n");
        }
        
        printf("Diferença em anos: %.1f\n", diff(random[0], random[1]));

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

