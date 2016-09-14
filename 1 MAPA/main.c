#include <stdio.h>
#include <stdlib.h>
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

void imprimir(int matriz[15][15]);
void jugar(int mapa[15][15]);

int main(void)
{
	int matriz[15][15]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						{1,10,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				    	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
					  	};
	
	imprimir(matriz);
	
	jugar(matriz);
		
	return 0;	
}

void imprimir(int mapa[15][15])
{	
	
	int i,j;

	system("CLS");	
	for(i=0; i<15; i++)
	{
		printf("\n");
		for(j=0; j<15; j++)
		{
			if(mapa[i][j]==0)
			{
				printf(" ");
			}
			
			if(mapa[i][j]==1)
			{
				printf("%c",47);
			}
			 
			if(mapa[i][j]==10)
			{
				printf("*");
			}
		}
	}	
}

void jugar(int mapa[15][15])
{
	int tecla, fp, cp;
	
	tecla=0;
	
	fp=1; cp=1;
	
	while(tecla!='s')
	{
		tecla=0;
		tecla=getch();
		
		mapa[fp][cp]=0;
		
		if(tecla==DERECHA)
		{
			if(mapa[fp][cp+1]==0)
			{
				cp++;
			}
		}
		if(tecla==IZQUIERDA)
		{
			if(mapa[fp][cp-1]==0)
			{
				cp--;
			}
		}
		if(tecla==ARRIBA)
		{
			if(mapa[fp-1][cp]==0)
			{
				fp--;
			}
		}
		if(tecla==ABAJO)
		{
			if(mapa[fp+1][cp]==0)
			{
				fp++;
			}
		}
	
		mapa[fp][cp]=10;
		imprimir(mapa);
		
	}
}



