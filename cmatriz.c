#include<stdio.h>

main()
{	
	int l,c;
	float M[4][5],x[4],n,lbd,m1,m2,m3,m4;
	FILE *in;
		
	in=fopen("matrizcompleta.c","r");
	
		
	for(l=0;l<4;l++)		//Gerando a matriz
	{
		for(c=0;c<5;c++)
		{
			fscanf(in,"%f\t",&n);
			
			M[l][c]=n;
		}
		printf("\n");
	}
	
	
	printf("\nMatriz Completa:\n");
	
	for(l=0;l<4;l++)				//imprimindo a matriz
	{
		for(c=0;c<5;c++)
			
			printf("%.2f\t",M[l][c]);
		
		printf("\n");
	}
	printf("\n\n");
	
	
	//Zerando o primeiro elemento da segunda linha
	
	lbd=M[1][0]/M[0][0];
	M[1][0]=M[1][0]-(lbd*M[0][0]);
	
     
}
