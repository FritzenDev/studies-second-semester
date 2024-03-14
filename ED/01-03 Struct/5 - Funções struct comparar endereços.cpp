#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
13. Crie uma estrutura Endereco que contenha os campos rua, numero, cidade e
cep.
14. Implemente uma função que compare dois endereços e retorne verdadeiro se
forem iguais.
15.Declare uma função que receba um endereço e imprima seus dados formatados.
*/

struct address {
	char rua[30];
	int num;
	char cidade[30];
	int cep;
};

int compare(struct address a1, struct address a2) {
    if ((strcmp(a1.rua, a2.rua) == 0) && (a1.num == a2.num) && (strcmp(a1.cidade, a2.cidade) == 0) && (a1.cep == a2.cep)) {
        return 1;
    } else {
        return 0;
    }
}

void form_address(struct address a, int choice) {
	if (choice == 1) {
		printf("\nRua: %s\n", a.rua);
		printf("Número: %i\n", a.num);
		printf("Cidade: %s\n", a.cidade);
		printf("CEP: %i\n", a.cep);
	} else if (choice == 2) {
		printf("\nRua: %s\n", a.rua);
		printf("Número: %i\n", a.num);
		printf("Cidade: %s\n", a.cidade);
		printf("CEP: %i\n", a.cep);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
    	struct address random[2];
    	printf("Digite 2 endereços\n");
    	for (int i = 0; i < 2; i++) {
    		printf("Digite o %i° endereço:\n", i+1);
    		printf("\nRua: ");
    		scanf(" %[^\n]", &random[i].rua);
    		
    		printf("Número: ");
    		scanf("%i", &random[i].num);
    		
    		printf("Cidade: ");
    		scanf(" %[^\n]", &random[i].cidade);
    		
    		printf("CEP: ");
    		scanf("%i", &random[i].cep);
    		printf("\n");
		}
		
		if (compare(random[0], random[1])) {
			printf("Os endereços são iguais\n");
		} else {
			printf("Os endereços não são iguais\n");
		}
		int escolha;
		printf("\nEscolha 1 endereço para ser exibido (1 ou 2): ");
		scanf("%i", &escolha);
		
		if (escolha == 1) {
			form_address(random[0], escolha);
		} else if (escolha == 2) {
			form_address(random[1], escolha);
		} else {
			printf("Número de escolha inválido!");
		}

    	scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

    return 0;
}

