#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/***
	ESTE ARQUIVO CONTEM A IMPLEMENTACAO DE TODAS AS FUNCOES LISTADAS NO ARQUIVO "pilha.h".

	O TIPO DE RETORNO E A LISTA DE PARAMETROS DAS FUNCOES DEVE OBEDECER AS ASSINATURAS
	DESSAS FUNCOES QUE ESTA NO ARQUIVO "pilha.h".

	SE FOR IMPLEMENTAR UMA NOVA FUNCAO, COLOQUE A ASSINATURA DELA NO "pilha.h" E DEPOIS
	A IMPLEMENTE NESTE ARQUIVO

	ESTE ARQUIVO DEVE CONTER APENAS AS FUNCOES USADAS PARA A MANIPULACAO DO TAD PILHA E
	ELE NAO CONTEM A FUNCAO "main()".
***/

Pilha* novaPilha()
{
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->inicio = NULL;
	return p;
}

int pilhaVazia(Pilha* p)
{
	if(p->inicio == NULL)
		return 1;
	else return 0;
}

Pilha* push(Pilha* p, int elem)
{
	// Cria uma nova caixinha para armazenar o novo valor
	No *novo = (No*)malloc(sizeof(No));
	// Preenche os campos da caixinha
	novo->dado = elem;				// Atribui o valor
	novo->prox = p->inicio;			// Liga a nova caixinha ao antigo topo
	p->inicio = novo;				// Atualiza o topo da pilha
	
	// Retorna a nova caixinha que será o atual topo
	return p;
}

Pilha* pop(Pilha* p)
{
	// Verifica se a pilha está vazia
	if(pilhaVazia(p))
		return NULL;

	// Caso a pilha não esteja vazia, cria um auxiliar
	No *aux = p->inicio->prox;
	// Apaga o topo da pilha
	free(p->inicio);
	// Faz o ponteiro do topo da pilha apontar para o elemento que está abaixo dele
	p->inicio = aux;

	// Retorna p, que será o novo topo
	return p;
}

No* topo(Pilha* p)
{
	if(pilhaVazia(p))
		return NULL;
	else
		return p->inicio;
}

void imprimePilha(Pilha *p)
{
	No *aux = p->inicio;
	while(aux != NULL)
	{
		printf("%d ", aux->dado);
		aux = aux->prox;
		
	}
	printf("\n");
}

int acharPilha(Pilha* vet[], int nPilhas, int elem)
{
	int i;
	for(i=0;i<nPilhas;i++)
	{
		Pilha *p = vet[i];
		No *aux = p->inicio;
		while(aux!=NULL)
		{
			if(aux->dado==elem)
				return i;
				
				aux= aux->prox;
		}
	}
	
}

void coloqueEm(Pilha *p[],int n1, int n2, int nPilhas)
{
	
	if(n1 == n2)
	{
		
	}
	
	else
	{
	int indice = acharPilha(p,nPilhas,n1);
	int indice2 = acharPilha(p,nPilhas,n2);
	
	No *aux = p[indice]->inicio;
	
		while(aux->dado != n1)
		{
			int val = topo(p[indice])->dado;
			p[val] = push(p[val],val);
			p[indice] = pop(p[indice]);
			aux = aux->prox;
		}
		aux = p[indice2]->inicio;
		while(aux->dado != n2)
		{
			int val = topo(p[indice2])->dado;
			p[val] = push(p[val],val);
			p[indice2] = pop(p[indice2]);
			aux = aux->prox;
		}
		int val = topo(p[indice])->dado;
		p[indice2] = push(p[indice2],val);
		p[indice] = pop(p[indice]);
	}
}

void coloqueNo(Pilha *p[], int n1, int n2, int nPilhas)
{
		if(n1 == n2)
		{
		
		}
		else{
		int indice = acharPilha(p,nPilhas,n1);
		int indice2 = acharPilha(p,nPilhas,n2);
	
		No *aux = p[indice]->inicio;
	
		while(aux->dado != n1)
		{
			int val = topo(p[indice])->dado;
			p[val] = push(p[val],val);
			p[indice] = pop(p[indice]);
			aux = aux->prox;
		}
		int val = topo(p[indice])->dado;
		p[indice2] = push(p[indice2],val);
		pop(p[indice]);
		}
}

void empilheNo(Pilha *p[], int n1, int n2,  int nPilhas)
{		
		if(n1 == n2)
		{
		
		}
		else
		{
		int indice = acharPilha(p,nPilhas,n1);
		int indice2 = acharPilha(p,nPilhas,n2);
		
		Pilha* p2 = novaPilha();
		
		No *aux = p[indice]->inicio;
		int val;
			while(p[indice]->inicio != NULL)
			{
			
			val = topo(p[indice])->dado;
			push(p2,val);
			pop(p[indice]);
			aux = aux->prox;
			}
			aux = p2->inicio;
			while(p2->inicio != NULL)
			{
			val = topo(p2)->dado;
			push(p[indice2],val);
			pop(p2);
			}
		 }
}

void empilheEm(Pilha *p[], int n1, int n2,  int nPilhas)
{		
		if(n1 == n2)
		{
		
		}
		else
		{
		int indice = acharPilha(p,nPilhas,n1);
		int indice2 = acharPilha(p,nPilhas,n2);
		
		No *aux = p[indice2]->inicio;
		
		while(aux->dado != n2)
		{
			int val = topo(p[indice2])->dado;
			push(p[val],val);
			pop(p[indice2]);
			aux = aux->prox;
		}
		empilheNo(p,n1,n2,nPilhas);
		}
}

void inverterPilha(Pilha *p[], int nPilhas)
{			
	int i = 0;
		while(i<=nPilhas)
		{
			Pilha* p2 = novaPilha();
			No *aux = p[i]->inicio;
			
			
			while(aux != NULL)
			{
			
			push(p2,aux->dado);
			aux = aux->prox;
			}
			printf("%d: ",i);
			imprimePilha(p2);
			
			i++;
			if(i==nPilhas)
				break;
		}
			
}









