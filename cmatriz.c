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
	
	
	//Zerando os elementos da primeira coluna exceto o primeiro
	
	for(l=1;l<4;l++)
	{
        lbd=M[l][0]/M[0][0];

		for(c=0;c<5;c++)
		
			M[l][c]=M[l][c]-(lbd*M[0][c]);
	
	} 
	
	
	//Repetindo para segunda coluna a partir do item 3    
	   
    for(l=2;l<4;l++)
	{
        lbd=M[l][1]/M[1][1];

		for(c=0;c<5;c++)

			M[l][c]=M[l][c]-(lbd*M[1][c]);

	}  
	
	
	for(l=3;l<4;l++)
	{
        	lbd=M[l][2]/M[2][2];
		for(c=0;c<5;c++)

			M[l][c]=M[l][c]-(lbd*M[2][c]);

	}
     
}
