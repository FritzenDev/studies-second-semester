#include <stdio.h>
#include <stdlib.h>

//Estrutura do nodo
struct nodo{
	int info;
	struct nodo *prox;
	struct nodo *ant;
};

//Estrutura do descritor da lista
struct lista{
	struct nodo *primeiro;
	struct nodo *ultimo;
};

//Fun��o de Inicializa��o da Lista
struct lista *init(){
	struct lista* temp = (struct lista *)malloc(sizeof(struct lista)); //Alocando o descritor da Lista
	temp->primeiro = NULL; //Fazendo o ponteiro primeiro apontar para NULL
	temp->ultimo = NULL; //Fazendo o ponteiro ultimo apontar para NULL
	return temp;  //Retornando o descritor da lista alocado
}

//Fun��o de Destrui��o da Lista de forma recursiva
void finalize(struct nodo *nodo){
	if(nodo == NULL){
		return;
	}
	else{
		finalize(nodo->prox);  //Chamada recursiva da fun��o finalize 
		free(nodo);
	}

}

//Fun��o de Inser��o na Lista
void insere(struct nodo* anterior, struct lista *desc, int info){
	if(anterior == NULL){ //Inserindo na primeira posi��o da Lista ou quando a Lista est� vazia
		if(desc->primeiro == NULL){
			struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));  //Alocando um novo nodo
			novo_nodo->info = info; //Atribuindo a informa��o ao novo nodo
			novo_nodo->prox = NULL; //Fazendo o novo nodo ponteiro pr�ximo receber NULL
			novo_nodo->ant = NULL; //Fazendo o novo nodo ponteiro anterior receber NULL
			desc->primeiro = novo_nodo; //Fazendo descritor primeiro receber o novo nodo
			desc->ultimo = novo_nodo; //Fazendo descritor ultimo receber o novo nodo
		}else{
			struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));  //Alocando um novo nodo
			novo_nodo->info = info; //Atribuindo a informação ao novo nodo
			novo_nodo->prox = desc->primeiro; //Fazendo o novo nodo ponteiro pr�ximo receber descritor primeiro
			novo_nodo->ant = NULL; //Fazendo o novo nodo ponteiro anterior receber NULL
			novo_nodo->prox->ant = novo_nodo; //Fazendo o nodo pr�ximo do novo nodo apontar para o novo nodo
			desc->primeiro = novo_nodo; //Fazendo descritor ultimo receber o novo nodo
		}
	}else{
		struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));  //Alocando um novo nodo
		novo_nodo->info = info; //Atribuindo a informa��o ao novo nodo
		novo_nodo->prox = anterior->prox; //Fazendo o novo nodo ponteiro pr�ximo apontar para o anterior próximo
		novo_nodo->ant = anterior; //Fazendo o novo nodo anterior receber o nodo anterior
		anterior->prox = novo_nodo; //Fazendo o nodo anterior ponteiro pr�ximo recebe novo nodo
		if(anterior == desc->ultimo){
			desc->ultimo = novo_nodo; //Fazendo descritor ultimo receber novo nodo
		}else{
			novo_nodo->prox->ant = novo_nodo; //Fazendo o nodo pr�ximo do novo nodo apontar para o novo nodo
		}
	}
}

//Fun��o de Remo��o na Lista
void remover(struct nodo* ptr, struct lista *desc){
	if(ptr == NULL){
		printf("Erro\n");
		return;
	}else{
		if(ptr->ant != NULL){ //Verificando se o ponteiro tem um nodo anterior a ele e ajustando ponteiros
			ptr->ant->prox = ptr->prox;
		}
		else{
			desc->primeiro = ptr->prox;
		}
		if(ptr->prox != NULL){ //Verificando se o ponteiro tem um nodo próximo a ele e ajustando ponteiros
			ptr->prox->ant = ptr->ant;
		}
		else{
			desc->ultimo = ptr->ant;
		}
	}
	free(ptr); //Liberando ponteiro
}

//Fun��o de Busca pela posi��o na Lista
struct nodo *get(struct lista *desc, int posicao){
	struct nodo *temp = desc->primeiro;
	if(temp == NULL){ //Verifica se a Lista est� vazia
		return NULL;
	}else{
		if(posicao < 1){ //Verifica se a posi��o � valida
			return NULL;
		}
		while(posicao != 1 && temp != NULL){ //La�oo de repeti��o para percorrer os nodos at� chegar na posi��o
			posicao = posicao - 1;
			temp = temp->prox;
		}
		return temp; //Retorna o nodo encontrado ou NULL
	}
}

//Fun��o de Busca pela informa��o na Lista
struct nodo *locate(struct lista *desc, int info){
	struct nodo *temp = desc->primeiro;
	if(temp == NULL){ //Verifica se a Lista est� vazia
		return NULL;
	}else{
		while(temp != NULL){ //La�o de repeti��o para percorrer os nodo
			if(temp->info == info){ //Verifica se o nodo cont�m a informa��o procurada
				return temp;
			}
			temp = temp->prox;
		}
	}
	return NULL;
}



int main(){

	struct lista *lista;
	struct nodo *temp;

	//Inicializa a Lista
	lista = init();

	//Inserindo nodos na Lista sempre na primeira posi��o
	insere(NULL,lista, 5);
	insere(NULL,lista, 4);
	insere(NULL,lista, 3);
	insere(NULL,lista, 1);
	
	//inserindo um novo nodo ap�s o nodo que tem a informa��o 1
	insere(get(lista, 1), lista, 2);

	//Percorrendo a Lista e imprimindo os nodos
	temp = lista->primeiro;

	while(temp!=NULL){
		printf("%d\n", temp->info);
		temp = temp->prox;
	}
	printf("\n");
	//Removendo o quarto elemento da lista
	remover(locate(lista, 4), lista);
	
	//Percorrendo a Lista e imprimindo os nodos
	temp = lista->ultimo;

	while(temp!=NULL){
		printf("%d\n", temp->info);
		temp = temp->ant;
	}
	
	//Finalizando a Lista
	finalize(lista->primeiro);
	free(lista);
	
}
