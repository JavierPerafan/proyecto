#include <stdio.h>
#include <stdlib.h>

#define dimensionarF(n) (int*)malloc(sizeof(int)*n);

void freeF ( int **vector, int n );
int **dimensionarMF ( int n, int longitud );
//proceso para llenar la matriz de los kilos
void llenarKilos(int **matrizKilos);
//proceso para contar el total de los kilos
void totalKilos(int **matrizKilos);
//proceso para calcular el pago por los kilos
void pagaKilos(int **matrizKilos, int *sueldo);


int main(int argc, char **argv)
{
	//declaro matrices y arreglos
	int *sueldo;
	int **matrizKilos;
	//dimensionamos las matrices o arreglos
	matrizKilos= dimensionarMF (2,7);
	sueldo= dimensionarF(2);
				//nombramos las funciones
	llenarKilos(matrizKilos);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 7; j++)
			{
			printf(" %d",matrizKilos[i][j]);
			}
			printf("\n");
		}
		
			totalKilos(matrizKilos);
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					printf(" %d",matrizKilos[i][j]);
				}
				printf("\n");
			}
			
			pagaKilos(matrizKilos, sueldo);
			for (int i = 0; i < 2; i++)
				{
					printf(" %d",sueldo[i]);
				}
	
			
		
	
	
	freeF(matrizKilos,20);
	free(sueldo);
	return 0;
}

void llenarKilos(int **matrizKilos)
{
	int contador = 25;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			
			matrizKilos[i][j]=contador;
			contador= contador + 5;
			
			if(j==6)
			{
				matrizKilos[i][j]=0;
			}
		}
	}
	
}
void totalKilos (int **matrizKilos)
{
	int total;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<6;j++)
			{
				total=matrizKilos[i][j]+total;
			}
				matrizKilos[i][6]=total;
				total=0;
				
		}
}
void pagaKilos(int **matrizKilos, int *sueldo)
{
	int valorKilos;
	for(int i=0;i<2;i++)
	{
		valorKilos=matrizKilos[i][6]*650;
		sueldo[i]=valorKilos;
		valorKilos=0;
	}
}

int **dimensionarMF ( int n, int longitud )
{
	int **vector;
	vector = (int**) malloc ( sizeof(int*) * n);
	for ( int i = 0 ; i < n ; i++ )
	{
		vector[i] = dimensionarF ( longitud );
	}
	return vector;
 }

void freeF ( int **vector, int n )
{
	for ( int i = 0 ; i < n ; i++ )
	{
		free ( vector [ i ] );
	}
	free( vector );
}

