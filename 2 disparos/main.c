#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define f 20
#define c 15
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

void imprimir(int matriz[f][c]);
void jugar(int mapa[f][c]);

int main(void)
{
	int matriz[f][c]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
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
				      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				      {1,0,10,0,0,0,0,0,0,0,0,0,0,0,1},
					  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
					  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					 };
	
	imprimir(matriz);
	
	jugar(matriz);
		
	return 0;	
}

void imprimir(int mapa[f][c])
{	
	
	int i,j;

	system("CLS");	
	for(i=0; i<f; i++)
	{
		printf("\n");
		for(j=0; j<c; j++)
		{
			if(mapa[i][j]==0)
			{
				printf(" ");
			}
			
			if(mapa[i][j]==1)
			{
				printf("%c",178);
			}
			 
			if(mapa[i][j]==10)
			{
				printf("%c",1);
			}
			if(mapa[i][j]==2)
			{
				printf("%c",43);
			}
			if(mapa[i][j]==3)
			{
				printf("%c",2);
			}
		}
	}	
}

void jugar(int mapa[f][c])
{
	int tecla, fp, cp, fs, cs, t, ef,ec;
	
	tecla=0;
	
	fp=17; cp=2;
	fs=22; cs=22;
	ef=2; ec=4;
	mapa[ef][ec]=3;
	
	t=0;
	while(tecla!='s')
	{
		tecla=0;
		if(kbhit())
		  tecla=getch();
		
		mapa[fp][cp]=0;
		mapa[fs][cs]=0;
		
		
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
		
/////////// DISPAROS //////////////	

		if(tecla=='t' && t==0)
		{
			fs=fp-1;
			cs=cp;
			mapa[fs][cs]=2;
			t=1;
	    }
  
		if(t==1)
		{
			mapa[fs][cs]=0;
				
			if(mapa[fs-1][cs]==0)
			{
				fs--;
				mapa[fs][cs]=2;				
			}
			else
			if(mapa[fs-1][cs]==3)
			{
				t=0;
				mapa[fs][cs]=0;
				mapa[ef][ec]=0;
			}
			else
			{
				t=0;
				mapa[fs][cs]=0;
		    }
		}
		
		imprimir(mapa);
		Sleep(100);
	}
}
