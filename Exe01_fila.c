#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
	/*guarda o inicio da fila*/
	int ini;
	/*guarda o fim da fila*/
	int fim;
	/*tamanho da fila*/
	int tam;
	/*vetor de elementos*/
	int *vetor;
} Fila;

int empty (Fila *f) {
	return (f->ini == f->fim);
}

int full (Fila *f) {
	return (f->fim == f->tam);
}

Fila* create_queue (int tam) {
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->ini = 0;
	f->fim = 0;
	f->tam = tam;
	f->vetor = (int*)malloc(tam*sizeof(int));
	return f;
}

void enqueue (Fila *f, int e) {
	if (full(f)) {
		printf("fila cheia: capacidade esgotada!");
		exit(1); /*aborta programa*/
	}
	f->vetor[f->fim] = e; /*insere elemento*/
	f->fim = f->fim + 1; /*incremento*/
}

int dequeue (Fila *f) {
	if (empty(f)) {
		printf("fila vazia!");
	exit(1); /*aborta programa*/
}

int v = f->vetor[f->ini]; /*guarda o elemento*/
	f->ini = f->ini + 1; /*incremento*/
	return v;
}

void free_queue (Fila *f) {
	free(f->vetor);
	free(f);
}

int main (int argc, char *argv[]) {
	
	int cont;
	int tam = 100;

	Fila *par = create_queue (tam);
	Fila *impar = create_queue (tam);

	for (cont = 1; cont <= tam; cont++)
	{

		if (cont % 2 == 0)
		{
			enqueue(par, cont);
		}
		else
		{
			enqueue(impar, cont);
		}
	}
	
	printf("\nFILA PAR\n");

	while(!empty(par) ) {
		int e = dequeue(par);
		printf("%d\t", e);

		if (e % 10 == 0 )
		{
			printf("\n");
		}
	}

	printf("\nFILA IMPAR\n");

	while(!empty(impar) ) {
		int e = dequeue(impar);
		printf("%d\t", e);

		if (e % 10 == 1)
		{
			printf("\n");
		}
	}

	printf("\n");
	
	free_queue (par);
	free_queue (impar);
	return 0;
}