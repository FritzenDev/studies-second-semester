#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*
2. Implemente uma função chamada newcalloc(), que faz exatamente o que a calloc() faz. Faça ela
usando as funções malloc() e a memset(), que pertence a biblioteca string.h e recebe três
argumentos (o ponteiro, o que queremos colocar em todas as posições do vetor e o número de
bytes): memset(ptr, 1, numero * tamanho_em_bytes).
*/

void* newcalloc(int num, int size) {
	void *ptr;
	ptr = malloc(num * size); // Não necessário (int *) pois estamos refazendo a função
	// Quando puxarmos o newcalloc, aí sim colocamos o (int *)
	
	if (ptr == NULL) { //Falha ao alocar memória
		return NULL;
	}
	
	memset(ptr, 0, num * size); //Inicializa a memória alocada em 0
	return ptr;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		
		int *ptr;
		ptr = (int *)newcalloc(10,sizeof(int));
		if (ptr == NULL) {
			printf("Falha na alocação de memória");
			exit(1);
		}
		
		for (int i = 0; i < 10; i++) {
			ptr[i] = i*i;
		}
		
		for (int i = 0; i < 10; i++) {
			printf("A posição %i tem o valor %i\n", i, ptr[i]);
		}
		
		free(ptr);
		ptr = NULL;

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

