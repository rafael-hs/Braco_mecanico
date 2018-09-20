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
		for(i=0;i<opw;i++)
		{
			p[i] = novaPilha();
			p[i] = push(p[i], i);
		}
		for(j=0;j<opw;j++)
		{
			printf("%d: ",j);
			imprimePilha(p[j]);
		}
		//system("clear");
		char word[8],word2[3];
		int n1,n2;
		int resultadoDeSaida=0; 
		do
		{
		push(p[3],4);
		pop(p[4]);
		push(p[3],2);
		pop(p[2]);
		push(p[1],0);
		pop(p[0]);
		
		for(j=0;j<opw;j++)
		{
			printf("%d: ",j);
			imprimePilha(p[j]);
		}
		
		coloqueNo(p,4,1,opw);	
		
		for(j=0;j<opw;j++)
		{
			printf("%d: ",j);
			imprimePilha(p[j]);
		}
		
		
		scanf("%s", word);
		if(strcmp(word,"fim")==0)
		{
		resultadoDeSaida = 1;
		break;
		}
		scanf("%d %s %d",&n1,word2,&n2);
		printf("%s\n",word);
		printf("%s\n",word2);
		printf("%d\n",n1);
		printf("%d\n",n2);
		
		
		}
		while(resultadoDeSaida!=1);{printf("saindo do programa...\n");}
		//mostrar a lista de pilhas
		//for(j=0;j<opw;j++)
		//{
		//	printf("%d: ",j);
		//	imprimePilha(p[j]);
		//}
			
}
