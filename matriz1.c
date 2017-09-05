#include<stdio.h>

main()
{	
	int l,c,i;
	float M[3][4],x[4],v[4],n,lbd,m1,m2,m3,m4;
	FILE *in;
		
	in=fopen("matrizcompleta1.c","r");
	
		
	for(l=0;l<4;l++)		//Gerando a matriz
	{
		for(c=0;c<4;c++)
		{
			fscanf(in,"%f\t",&n);
			
			M[l][c]=n;
		}
		printf("\n");
	}
	
	
	printf("\nMatriz Completa:\n");
	
	for(l=0;l<3;l++)				//imprimindo a matriz
	{
		for(c=0;c<4;c++)
			
			printf("%.2f\t",M[l][c]);
		
		printf("\n");
	}
	printf("\n\n");
	
	
	for(l=1;l<3;l++)				
	{
		if(M[l][0]>M[l-1][0])
		{
			for(c=0;c<4;c++)
			{
				v[c]=M[l-1][c];
				M[l-1][c]=M[l][c];
				M[l][c]=v[c];
			}
		}
	}
	
	
	for(l=1;l<3;l++)
	{
		if(M[0][0]!=0)
		{
        	lbd=M[l][0]/M[0][0];
	
			for(c=0;c<4;c++)
		
				M[l][c]=M[l][c]-(lbd*M[0][c]);
		}
	}
	
	
	printf("\nMatriz modificada:\n");
	
	for(l=0;l<3;l++)				//imprimindo a matriz
	{
		for(c=0;c<4;c++)
			
			printf("%.2f\t",M[l][c]);
		
		printf("\n");
	}
	printf("\n\n");
	
	
	
}
				
