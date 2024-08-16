#include <stdio.h>
#include <stdlib.h>

//Estrutura do nodo
struct nodo{
	int info;
	struct nodo *prox;
};

//Estrutura do descritor da lista
struct lista{
	struct nodo *primeiro;
};

//Fun��o de Inicializa��o da Lista
struct lista *init(){
	struct lista* temp = (struct lista *)malloc(sizeof(struct lista)); //Alocando o descritor da Lista
	temp->primeiro = NULL; //Fazendo o ponteiro primeiro apontar para NULL
	return temp; //Retornando o descritor da lista alocado
}

//Fun��o de Destrui��o da Lista
void finalize(struct lista *desc){
	struct nodo *inicio, *temp;
	inicio = desc->primeiro; //Inicio recebe o primeiro nodo da Lista
	while(inicio != NULL){
		temp = inicio->prox;
		free(inicio); //Desalocando o endere�o de mem�ria apontado por inicio
		inicio = temp;
	}
	free(desc); //Desalocando o descritor da Lista
}

//Fun��o de Inser��o na Lista
void insere(struct nodo* anterior, struct lista *desc, int info){
	if(anterior == NULL){ //Inserindo na primeira posi��o da Lista ou quando a Lista est� vazia
		struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo)); //Alocando um novo nodo
		novo_nodo->info = info; //Atribuindo a informa��o ao novo nodo
		novo_nodo->prox = desc->primeiro; //Fazendo o novo nodo ponteiro pr�ximo apontar para descritor primeiro (que pode ser o primeiro nodo ou NULL)
		desc->primeiro = novo_nodo; //Coloca o novo nodo como primeiro na Lista
	}else{
		struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo)); //Alocando um novo nodo
		novo_nodo->info = info; //Atribuindo a informa��o ao novo nodo
		novo_nodo->prox = anterior->prox; //Fazendo o novo nodo ponteiro pr�ximo apontar para o anterior pr�ximo
		anterior->prox = novo_nodo; //Fazendo o anterior pr�ximo apontar para novo nodo
	}
}

//Fun��o de Remo��o na Lista
void remover(struct nodo* anterior, struct lista *desc){
	struct nodo *temp;
	if(anterior == NULL){
		if(desc->primeiro == NULL){ //Erro pois a Lista est� vazia
			printf("Erro\n");
			return;
		}else { //Removendo o primeiro nodo da lista
			temp = desc->primeiro; 
			desc->primeiro = desc->primeiro->prox;
			free(temp);
		}
	}else {
		if(anterior->prox == NULL){ //Erro pois o nodo anterior era o �lltimo da Lista
			printf("Erro\n");
			return;
		}else { //Removendo o nodo pr�ximo do nodo anterior
			temp = anterior->prox;
			anterior->prox = temp->prox;
			free(temp);
		}
	}
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
		while(posicao != 1 && temp != NULL){ //La�o de repeti��o para percorrer os nodos at� chegar na posi��o
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
	remover(locate(lista, 3), lista);
	
	//Percorrendo a Lista e imprimindo os nodos
	temp = lista->primeiro;

	while(temp!=NULL){
		printf("%d\n", temp->info);
		temp = temp->prox;
	}
	
	//Finalizando a Lista
	finalize(lista);


}
