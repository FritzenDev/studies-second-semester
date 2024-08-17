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

//Função de Inicialização da Lista
struct lista *init(){
	struct lista* temp = (struct lista *)malloc(sizeof(struct lista)); //Alocando o descritor da Lista
	temp->primeiro = NULL; //Fazendo o ponteiro primeiro apontar para NULL
	temp->ultimo = NULL; //Fazendo o ponteiro ultimo apontar para NULL
	return temp;  //Retornando o descritor da lista alocado
}

//Função de Destruição da Lista de forma recursiva
void finalize(struct nodo *nodo){
	if(nodo == NULL){
		return;
	}
	else{
		finalize(nodo->prox);  //Chamada recursiva da função finalize 
		free(nodo);
	}

}

//Função de Inserção na Lista
void insere(struct nodo* anterior, struct lista *desc, int info){
	if(anterior == NULL){ //Inserindo na primeira posição da Lista ou quando a Lista está vazia
		if(desc->primeiro == NULL){
			struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));  //Alocando um novo nodo
			novo_nodo->info = info; //Atribuindo a informação ao novo nodo
			novo_nodo->prox = NULL; //Fazendo o novo nodo ponteiro próximo receber NULL
			novo_nodo->ant = NULL; //Fazendo o novo nodo ponteiro anterior receber NULL
			desc->primeiro = novo_nodo; //Fazendo descritor primeiro receber o novo nodo
			desc->ultimo = novo_nodo; //Fazendo descritor ultimo receber o novo nodo
		}else{
			struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));  //Alocando um novo nodo
			novo_nodo->info = info; //Atribuindo a informaÃ§Ã£o ao novo nodo
			novo_nodo->prox = desc->primeiro; //Fazendo o novo nodo ponteiro próximo receber descritor primeiro
			novo_nodo->ant = NULL; //Fazendo o novo nodo ponteiro anterior receber NULL
			novo_nodo->prox->ant = novo_nodo; //Fazendo o nodo próximo do novo nodo apontar para o novo nodo
			desc->primeiro = novo_nodo; //Fazendo descritor ultimo receber o novo nodo
		}
	}else{
		struct nodo* novo_nodo = (struct nodo *)malloc(sizeof(struct nodo));  //Alocando um novo nodo
		novo_nodo->info = info; //Atribuindo a informação ao novo nodo
		novo_nodo->prox = anterior->prox; //Fazendo o novo nodo ponteiro próximo apontar para o anterior prÃ³ximo
		novo_nodo->ant = anterior; //Fazendo o novo nodo anterior receber o nodo anterior
		anterior->prox = novo_nodo; //Fazendo o nodo anterior ponteiro próximo recebe novo nodo
		if(anterior == desc->ultimo){
			desc->ultimo = novo_nodo; //Fazendo descritor ultimo receber novo nodo
		}else{
			novo_nodo->prox->ant = novo_nodo; //Fazendo o nodo próximo do novo nodo apontar para o novo nodo
		}
	}
}

//Função de Remoção na Lista
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
		if(ptr->prox != NULL){ //Verificando se o ponteiro tem um nodo prÃ³ximo a ele e ajustando ponteiros
			ptr->prox->ant = ptr->ant;
		}
		else{
			desc->ultimo = ptr->ant;
		}
	}
	free(ptr); //Liberando ponteiro
}

//Função de Busca pela posição na Lista
struct nodo *get(struct lista *desc, int posicao){
	struct nodo *temp = desc->primeiro;
	if(temp == NULL){ //Verifica se a Lista está vazia
		return NULL;
	}else{
		if(posicao < 1){ //Verifica se a posição é valida
			return NULL;
		}
		while(posicao != 1 && temp != NULL){ //Laçoo de repetição para percorrer os nodos até chegar na posição
			posicao = posicao - 1;
			temp = temp->prox;
		}
		return temp; //Retorna o nodo encontrado ou NULL
	}
}

//Função de Busca pela informação na Lista
struct nodo *locate(struct lista *desc, int info){
	struct nodo *temp = desc->primeiro;
	if(temp == NULL){ //Verifica se a Lista está vazia
		return NULL;
	}else{
		while(temp != NULL){ //Laço de repetição para percorrer os nodo
			if(temp->info == info){ //Verifica se o nodo contém a informação procurada
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

	//Inserindo nodos na Lista sempre na primeira posição
	insere(NULL,lista, 5);
	insere(NULL,lista, 4);
	insere(NULL,lista, 3);
	insere(NULL,lista, 1);
	
	//inserindo um novo nodo após o nodo que tem a informação 1
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
