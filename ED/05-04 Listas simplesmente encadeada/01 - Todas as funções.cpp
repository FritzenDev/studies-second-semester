#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*
Implemente uma lista encadeada na linguagem C, utilizando as estruturas apresentadas em aula.
Implemente as 6 funções descritas em aula. Dentro da função main, implemente um menu de
escolha de qual função o usuárioquer executar na lista.
*/

struct nodo {
	int info;
	struct nodo *prox;
}

struct list {
	struct nodo *first;
};

void start(struct list *list) {
	struct list* temp = (struct list*) malloc(sizeof(struct list));
	temp->first = NULL;
	return temp;
}

void insert(struct nodo* anterior, struct list *desc, info) {
	if(anterior == NULL) {
		if(desc->first == NULL){
			//Inserção caso a lista esteja vazia
			struct nodo* new_node = (struct node*) malloc(sizeof(struct node));
			new_node->info = info;
			new_node->prox = NULL;
			desc->first = new_node;
		} else {
			//Inserção para caso de inserir no início da lista
			struct nodo* new_node = (struct node*) malloc(sizeof(struct node));
			new_node->info = info;
			new_node->prox = desc->first;
			desc->first = new_node;
		}
	} else {
		//Inserção para os demais casos
		struct nodo* new_node = (struct node*) malloc(sizeof(struct node));
		new_node->info = info;
		new_node->prox = anterior->prox;
		anterior->prox = new_node;
	}
}

void remove(struct nodo* anterior, struct list *desc) {
	if (anterior == NULL) {
		if (desc->first == NULL) {
			//Retorna erro devido a lista estar vazia
			return erro;
		} else {
			//Remove o primeiro nodo da lista
			temp = desc->first;
			desc->first = desc->first->prox;
			free(temp);
		}
	} else {
		if (anterior->prox == NULL) {
			return erro;
		} else {
			//Remove o nodo apontado por 'prox' do anterior
			temp = anterior->prox;
			anterior->prox = temp->prox;
			free(temp);
		}
	}
}

void locate(struct list *desc, info) {
	temp = desc->first;
	if (temp == NULL) {
		//Retorna NULL pois a lista está vazia
		return NULL;
	} else {
		while (temp != NULL) {
			if (temp->info == info) {
				//Retorna o nodo encontrado
				return temp;
			}
			temp = temp->prox;
			
		}
	}
	//Caso percorrer toda a lista e não encontrar nodo, retornar null
	return NULL;
}

void get(struct list *desc, pos) {
	temp = desc->first;
	if (temp == NULL) {
		return NULL;
	} else {
		if (pos < 1) {
			//Retorna NULL pois a posição não existe
			return NULL;
		}
		while (pos != 1 && temp != NULL) {
			pos = pos - 1;
			temp = temp->prox;
			//Retorna temp, que pode ser o nodo encontrado ou NULL
			return temp;
		}
	}
}

void exit(struct list *desc) {
	start = desc->first;
	//O laço de repetição percorre toda lista desalocando seus nodos
	while (start != NULL) {
		temp = start->prox;
		free(start);
		start = temp;
		//Ao fim, o descritor da lista deve ser desalocado
		free(desc);
	}
}

int main () {
	setlocale(LC_ALL,"Portuguese");
	char continuar;

	do {
		int op, x;
		int var;
		
		printf("Deseja inicializar a lista? (0 - Sim | 1 - Não)\n");
		scanf("%i", &x);
		if (x == 0) {
			start(list);
			do {
				printf("1 - Inserir\n");
				printf("2 - Excluir\n");
				printf("3 - Buscar\n");
				printf("4 - Listar\n");
				printf("5 - Sair\n");
				scanf("%i", &op);
			
				switch (op) {
					case 1:
						//Inserir						
						insert()
						break;
					case 2:
						//Excluir
						break;
					case 3:
						//Buscar
						break;
					case 4:
						//Listar
						break;
					case 5:
						//Fechar
						break;
					default:
						printf("Opção inválida");
						break;
				}
			} while (op != 5)
		} else if (x == 1) {
			printf("Aplicativo encerrado!");
			exit(1);
		} else {
			printf("Opção inválida!");
			break;
		}
		

	   scanf("%s", &continuar);
	} while (continuar == 'S' || continuar == 's');

	return 0;
}

