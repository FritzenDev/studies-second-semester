#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*
2. Implemente uma fun��o chamada newcalloc(), que faz exatamente o que a calloc() faz. Fa�a ela
usando as fun��es malloc() e a memset(), que pertence a biblioteca string.h e recebe tr�s
argumentos (o ponteiro, o que queremos colocar em todas as posi��es do vetor e o n�mero de
bytes): memset(ptr, 1, numero * tamanho_em_bytes).
*/

void* newcalloc(int num, int size) {
	void *ptr;
	ptr = malloc(num * size); // N�o necess�rio (int *) pois estamos refazendo a fun��o
	// Quando puxarmos o newcalloc, a� sim colocamos o (int *)
	
	if (ptr == NULL) { //Falha ao alocar mem�ria
		return NULL;
	}
	
	memset(ptr, 0, num * size); //Inicializa a mem�ria alocada em 0
	return ptr;
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		
		int *ptr;
		ptr = (int *)newcalloc(10,sizeof(int));
		if (ptr == NULL) {
			printf("Falha na aloca��o de mem�ria");
			exit(1);
		}
		
		for (int i = 0; i < 10; i++) {
			ptr[i] = i*i;
		}
		
		for (int i = 0; i < 10; i++) {
			printf("A posi��o %i tem o valor %i\n", i, ptr[i]);
		}
		
		free(ptr);
		ptr = NULL;

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

