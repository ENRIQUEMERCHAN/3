#include <stdio.h>
#include <stdlib.h>

struct materia
{
	char nom[50];
	int semestre;
	int notas[4];
	float def;
};

struct Estudiante
{
	char nom[30];
	int edad, cedula;
	char carrera[50];
	struct materia mat[10];
};

int main(void)
{
	int i, j, k;
	
	struct Estudiante x;
	
	struct Estudiante sec[50];
	
	struct materia mat[10], notas[4];
	
	printf("\n ingrese nombre: ");
	fflush(stdin);
	gets(x.nom);
	printf("\n ingrese edad: ");
	scanf("%d",&x.edad);
	
	for(i=0; i<3; i++)// estidiantes
	{
		printf("\n\n Estudiante %d",i+1);
		printf("\n Nombre: ");
		fflush(stdin);
		gets(sec[i].nom);
		printf("\n edad: ");
		scanf("%d",&sec[i].edad);
		printf("\n cedula: ");
		scanf("%d",&sec[i].cedula);
		printf("\n carrera: ");
		fflush(stdin);
		gets(sec[i].carrera);
		
		for(j=0; j<3; j++)//materias por estudiantes
		{
			printf("\n nombre de la materia %d: ",j+1);
			fflush(stdin);
			gets(sec[i].mat[j].nom);
			printf("\n semestre: ");
			scanf("%d",&sec[i].mat[j].semestre);
			
			for(k=0; k<4; k++)
			{
				printf("\n %dnota: ",k+1);
				scanf("%d",&sec[i].mat[j].notas[k]);
				
			}
			
		}
	}
	
	printf("\n El nombre del estudiante solo es: %c",x.nom);
	
	printf("\n\n");
	for(i=0; i<3; i++)
	{
		printf("\n nombre: %s",sec[i].nom);
		printf("\n edad: %d",sec[i].edad);
		printf("\n cedula: %d",sec[i].cedula);
		printf("\n carrera: %s",sec[i].carrera);
		
		for(j=0; j<3; j++)
		{
			printf("\n materia: %s",sec[i].mat[j].nom);
			
			for(k=0; k<4; k++)
			{
				printf("\n %dnota: %d",k+1,sec[i].mat[j].notas[k]);
			}
		}
	}
	
	return 0;
}
