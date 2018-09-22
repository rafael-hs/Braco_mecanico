#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"
#include <string.h>

int main(void)
{
	int opcao, opw, num;
	int i,j;
	int numeroAchado;
	
		printf("digite a quantidade de blocos:\n");
		scanf("%d", &opw);
		Pilha *p[opw];
		system("clear");
		for(i=0;i<opw;i++)
		{
			p[i] = novaPilha();
			p[i] = push(p[i], i);
		}
		

		char word[8],word2[3];
		int n1,n2;
		int resultadoDeSaida=0; 
		do
		{
		
		scanf("%s", word);
		if(strcmp(word,"fim")==0)
		{
		resultadoDeSaida = 1;
		break;
		}
		scanf("%d %s %d",&n1,word2,&n2);
		
		
		if(strcmp(word,"coloque")==0)
		{
				if(strcmp(word2,"em")==0)
				{
					coloqueEm(p,n1,n2,opw);
					inverterPilha(p,opw);	
				}else
				{
					coloqueNo(p,n1,n2,opw);
					inverterPilha(p,opw);
				}
		}
		else if (strcmp(word,"empilhe")==0)
		{
				if(strcmp(word2,"em")==0)
				{
					empilheEm(p,n1,n2,opw);
					inverterPilha(p,opw);
				}
				else
				{
					empilheNo(p,n1,n2,opw);
					inverterPilha(p,opw);
				}
		}
		
		}
		while(resultadoDeSaida!=1);
		system("clear");
		{
		inverterPilha(p,opw);
		}
		//mostrar a lista de pilhas
		//for(j=0;j<opw;j++)
		//{
		//	printf("%d: ",j);
		//	imprimePilha(p[j]);
		//}
			
}
