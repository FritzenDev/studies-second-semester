#include <stdio.h>
#include <stdlib.h>

//Estrutura do nodo da Fila
struct nodo{
	int info;
	struct nodo *prox;
};

//Descritor da Fila
struct fila{
	struct nodo *inicio;
	struct nodo *fim;
};

//Fun��o de inicializa��o da Fila
struct fila *init(){
	struct fila* temp = (struct fila *)malloc(sizeof(struct fila));
	temp->inicio = NULL;
	temp->fim = NULL;
	return temp;
}

//Fun��o de destrui��o da Fila
void finalize(struct fila *desc){
	struct nodo *inicio, *temp;
	inicio = desc->inicio;
	while(inicio != NULL){
		temp = inicio->prox;
		free(inicio);
		inicio = temp;
	}
	free(desc);
}

//Fun��o de inser��o de um nodo na Fila
void enqueue(struct fila *desc, int info){
	struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));
	novo_nodo->info = info;
	novo_nodo->prox = NULL;
	if(desc->inicio == NULL){
		desc->inicio = novo_nodo;
	}else{
		desc->fim->prox = novo_nodo;
	}
	desc->fim = novo_nodo;
	
}

//Fun��o de remo��o de um nodo na Fila
void dequeue(struct fila *desc){
	struct nodo *temp;
	if(desc->inicio == NULL){
		printf("Erro\n");
		return;
	}else{
		temp = desc->inicio;
		desc->inicio = temp->prox;
		free(temp);
		if(desc->inicio == NULL){
			desc->fim = NULL;
		}
	}
}

int main(){

	struct fila *fila;

	fila = init();

	enqueue(fila, 5);
	enqueue(fila, 4);
	enqueue(fila, 3);
	enqueue(fila, 2);
	enqueue(fila, 1);


	struct nodo *temp = fila->inicio;

	printf("Imprimindo a Fila: \n");

	while(temp!=NULL){
		printf("%d\n", temp->info);
		temp = temp->prox;
	}


	finalize(fila);
}
