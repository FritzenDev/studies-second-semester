#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
10.Declare uma estrutura com alguns campos. Declare um ponteiro para essa 
estrutura e atribua a ele o endereço de uma variável dessa estrutura. Acesse os 
campos da estrutura usando o ponteiro e imprima seus valores.
*/

struct dez {
	int campo1 = 2;
	int campo2 = 10;
	int campo3 = 17;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	struct dez x;
    	struct dez *p;
		
		p = &x;
    	
    	printf("Campo 1: %i\n", p->campo1);
    	printf("Campo 2: %i\n", p->campo2);
    	printf("Campo 3: %i\n", p->campo3);

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

