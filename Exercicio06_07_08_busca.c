#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000000


void criaHeap(int *vetor, int i, int f)
{	
	int a;
	
	int auxiliar = vetor[i];
	
	int j = i * 2 + 1;
	
	while (j <= f)
	{
		if (j < f)
		{
			if(vetor[j] < vetor[j + 1])
			{
				j = j + 1;
			}
		}
		if(auxiliar < vetor[j])
		{
			vetor[i] = vetor[j];
			i = j;
			j = 2 * i + 1;
		} 
		else
		{
			j = f + 1;
		}
	}
	vetor[i] = auxiliar;
}

void heapSort(int *vetorOrigem, int tamanho)
{
	int a, i, tmp, contador;

	for (i = (tamanho / 2); i >= 0; i--)
	{
		criaHeap(vetorOrigem, i, tamanho - 1);
		contador++;
	}

	for (i = tamanho - 1; i >= 1; i--)
	{
		tmp = vetorOrigem[0];
		vetorOrigem[0] = vetorOrigem[i];
		vetorOrigem[i] = tmp;
		criaHeap(vetorOrigem, 0, i-1);
		contador++;
	}

	return;
}

void preencher(int *vetor, int topNumber)
{
	int i, aux;	

	for (i = 0; i < TAM; i++)
	{
		aux = rand() % topNumber;
		*(vetor + i) = aux;
	}	
}

void printVet(int *vetor)
{
	int i;
	int aux = 0;

	for (i = 0; i < TAM; i++)
	{
		printf("%d\t", vetor[i]);
		aux++;

		if (aux % 5 == 0){
			printf("\n");
		}
	}
}

void buscaSeq(int *vetor, int procurado)
{
	int i;

	for (i = 0; i < TAM; i++)
	{
		if (vetor[i] == procurado)
		{
			printf("Valor: %d - Encontrado na Posicao %d\n",procurado,i);
			return;
		}				
	}
	if (procurado > 0)
	{
		printf("Valor não encontrado\n");
	}
	else
	{
		printf("Saindo...\n");	
	}
}

void buscaBin(int *vetor, int procurado)
{
	int esquerda, direita, meio;

	esquerda = -1;
	direita = TAM;
	meio = TAM / 2;

	while ((meio > esquerda) && ( meio < direita))
	{
		if (procurado == vetor[meio])
		{
			printf("Valor: %d - Encontrado na Posicao %d\n",procurado,meio);
			return;
		}
		else if (procurado < vetor[meio])
		{
			direita = meio;
			meio = ((direita - esquerda) / 2) + esquerda;
		}
		else
		{
			esquerda = meio;
			meio = ((direita - esquerda) / 2) + esquerda;
		}
	}
	if (procurado > 0)
	{
		printf("Valor não encontrado\n");
	}
	else
	{
		printf("Saindo...\n");	
	}
}

int BuscaBinRec(int *vetor, int procurado, int esquerda, int direita, int meio)
{
	if (( meio > esquerda) && ( meio < direita))
	{
		if (procurado == vetor[meio])
		{
			return meio;
		}
		else if  (procurado < vetor[meio])
		{
			return BuscaBinRec(vetor, procurado, esquerda, meio, (((meio - esquerda) / 2) + esquerda));
		}
		else
		{
			return BuscaBinRec(vetor, procurado, meio, direita, (((direita - meio) / 2) + meio));
		}				
	}
	else
	{
		return -1;
	}
}

int main (int argc, char **argv)
{
	srand(time(NULL));	

	int vetor[TAM], x, pos;
	int topNumber = 1000000;

	preencher(vetor, topNumber);
	printf("Vetor Gerado com Sucesso!!! \n\n");
	printVet(vetor);
	printf("\nVetor Ordenado com Sucesso!!! \n\n");
	heapSort(vetor, TAM);
	printVet(vetor);

	do
	{
		printf("\nProcurar valor no vetor (BUSCA SEQUENCIAL - 0 para sair): ");
		scanf("%d",&x);
		buscaSeq(vetor, x);
	}	
	while (x > 0);

	do
	{
		printf("\nProcurar valor no vetor (BUSCA BINARIA ITERATIVA - 0 para sair): ");
		scanf("%d",&x);
		buscaBin(vetor, x);
	}	
	while (x > 0);

	do
	{
		printf("\nProcurar valor no vetor (BUSCA BINARIA RECURSIVA - 0 para sair): ");
		scanf("%d",&x);
		if (x > 0)
		{
			pos = BuscaBinRec(vetor, x, -1, TAM, TAM / 2);		
			if (pos >= 0)
			{
				printf("Valor: %d - Encontrado na Posicao %d\n",x,pos);
			}
			else
			{
				printf("Valor não encontrado\n");
			}	
		}
		else
		{
			printf("Saindo...\n");
		}		
	}	
	while (x > 0);

	return 0;
}