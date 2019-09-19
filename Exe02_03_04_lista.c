#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node* next;
} Lista;

Lista* criar (void) {
	return NULL;
}

Lista* inserir (Lista* lista, int elem) {
	Lista* novo =(Lista*)malloc(sizeof(Lista));
	
	novo->info = elem;
	novo->next = lista;
	return novo;
}


void imprimir (Lista *lista) {
	Lista *v; /*var. para percorrer a lista*/
	
	for (v = lista; v != NULL; v = v->next) {
		printf("Valor: %d\n", v->info);
	}
}

Lista* remover (Lista *lista, int elem){
	Lista* prv = NULL; Lista* v = lista;

	while ((v != NULL) && (v->info != elem)) {
		prv = v;
		v = v->next;
	}

	if (v == NULL) { return lista; }
	if (prv == NULL) { lista = v->next; }
	else { prv->next = v->next; }

	free (v);
	return lista;
}

int liberar (Lista *lista) {
	while (lista != NULL) {
		Lista *aux = lista->next; /*guarda ref. p/ prox.*/
		free (lista); /*libera a memoria apontada por v*/
		lista = aux; /*faz v apontar p/ o prox. elem.*/
	}
}

int conta_nos (Lista *lista)
{
	int nos = 0;
	Lista *contador;

	for (contador = lista; contador != NULL; contador = contador -> next)
	{
		// printf("No numero: # %d\n",nos);
		nos++;
	}

	return nos;
}

Lista* procurar (Lista* lista, int elem)
{
	Lista *contador;

	for (contador = lista; contador != NULL; contador = contador -> next)
	{
		if (contador -> info == elem)
		{
			return contador;
		}
	}
}

Lista* separa (Lista* lista, int n)
{	
	Lista *aux = NULL;
	Lista *nova = NULL;

	for (aux = lista; aux != NULL; aux = aux -> next)
	{
		if (aux -> info == n)
		{
			nova = aux -> next;
			aux -> next = NULL;
			break;
		}
	}

	return nova;
}

int main () {
	Lista *lista;
	Lista *no;
	Lista *separado;
	
	lista = criar ();
	separado = criar ();
	
	lista = inserir (lista, 1);
	lista = inserir (lista, 2);
	lista = inserir (lista, 4);
	lista = inserir (lista, 6);
	lista = inserir (lista, 7);
	lista = inserir (lista, 9);

	imprimir (lista);

	printf("Numero de nos da lista: %d\n",conta_nos(lista));

	no = procurar(lista, 2);

	printf("No encontrado - Conteudo %d\n", no -> info);

	printf("Lista de valores separados\n");

	separado = separa (lista, 4);

	imprimir(separado);

	printf("\n");



	liberar (lista);
	return 0;
}