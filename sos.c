#include<stdio.h>
#include<stdlib.h>

#include<math.h>


void imprime ( double **M, int dim)
{
	int l, c;
     
	for(l=0; l<dim; l++)
	{	
		for(c=0; c<dim+1; c++)
		
			printf("%lf\t", M[l][c]);
		
		printf("\n");
	}
}


int pivotamento (double **M, int dim)
{  
	int cont=0, l, c, d;
	double U, lambda;
   
	for(l=0; l<dim; l++)
	{   
		if(M[l][l] == 0)
		{
			for(d = l; d < dim; d++)
			{
				if(M[d][l] != 0)
				{
					for(c = 0; c < dim; c++)
					{
                    	U = M[l][c];
                        M[l][c] = M[d][c];
                        M[d][c] = U;
                    }
                    
                    d = dim;
                }
            }
            
            cont++;
        }
     
     
		if(M[l][l] != 0)
		{
        	for(d = l+1; d<dim; d++ )
            {
        	    lambda = -1.0 * M[d][l]/M[l][l];
			
				for(c=l; c<dim; c++)
				
			        M[d][c] = M[d][c]+(lambda*(M[l][c]));
	                    
                
            }
         }
	}
	
   	printf("\nQuantidade de troca : %d", cont);
   	
	return(cont);
}


void determinante ( double **M, int dim, int cont)
{
	int l;
	double det = 1;
	
	for(l=0; l<dim; l++)
	
		det *= M[l][l];
	
		
	if(cont % 2 == 0)
    	printf("%.1lf \n", det);
    else
    	printf("%.1lf \n", -1.0 * det);
 
}


void decomposicaoLU(double **M,int dim)     
{
	int i,j,k=0;
    double **U,**L;
    
    
    U = malloc (dim * sizeof (double *));
   for (i = 0; i < dim; ++i)
      U[i] = malloc ((dim+1) * sizeof (double));
    
    
    L = malloc (dim * sizeof (double *));
   for (i = 0; i < dim; ++i)
      L[i] = malloc ((dim+1) * sizeof (double));
      
      
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim+1; j++)
        {
            L[i][j]=0;
            U[i][j]=M[i][j]; //Criando a Matriz auxiliar a imagem da Matriz A
        }
    }
    
    
    printf("\n***Seja U, uma Matriz auxiliar como copia da Matriz A***\n");
    printf("----Matriz U antes----\n");
    imprime (U,dim);
    
    
    //Calculando os multiplicadores da Gauss
    //Movimenta a coluna
    for(j=0; j<dim+1; j++)
    {      
        printf("\n***Multiplicadores de Gauss da %d coluna***\n",j+1);
        
        //Movimenta a linha
        for(i=j+1; i<dim; i++)
        {
            if(U[i][j] == 0)
            
                printf("Posição[%d][%d] já é 0, não há necessidade de fazer eliminação de Gauss para este termo!\n",i,j);
            
            else
            {
                L[i][j]=U[i][j]/U[j][j];
                printf("L[%d][%d]=%.2f\n",i,j,L[i][j]);
                
                //Multiplico a linha do multiplicar por -(multiplicador)
                
                //Movimenta a coluna
                for(k=j; k<dim+1; k++)
                {
                    printf("\n----Multiplicando a %dx%d por %.2f----\n",j,k,-1*L[i][j]);              
                    imprime(U,dim);
                    printf("\n***Fazendo %.2f * %.2f = %.2f***\n",U[j][k],-1*L[i][j],U[j][k]*(-1*(L[i][j])));
                    printf("***Fazendo %.2f + %.2f = %.2f*** POS[%d][%d]\n",U[j][k]*(-1*(L[i][j])),U[i][k],U[i][k]+U[j][k]*(-1*(L[i][j])),i,k);
                    U[i][k]=U[i][k]+U[j][k]*(-1*(L[i][j]));
               
                    printf("\n----Matriz U depois----\n");    
                    imprime(U,dim);
                }      
            }      
            printf("\n");
		}
             
    }
    
    printf("\n\n*********RESULTADO FINAL**********\n");
    for(i=0; i<dim; i++)
           
            L[i][i]=1;
        
    printf("\n----Matriz L----\n");
    imprime(L,dim);
   
    printf("\n----Matriz U----\n");
    imprime(U,dim);
   
}
 
void inversa (double **M,int dim)
{
	int l,c;
	double x[dim],p,s=0.0;
	

	
	p = M[dim-1][dim];
	

	x[dim] = p / M[dim-1][(dim-1)];
	

	
	for(l=dim-1; l>=0; l--)
	{
		p = M[l][dim];
		
		for(c=l+1; c<(dim+1); c++)
			s = s + (M[l][c]*x[c]);
		
		x[l] = (p - s)/M[l][l];
		
		s = 0;
	}
	
	
	printf("\nSolução do Sistema\n");
	for(l=0; l<(dim+1); l++)
	
	   printf("\nX%d = %lf\t", l+1, x[l]);
	printf("\n");
}



void jacobi(double **M,int dim)
{
	int i,j,c=0;
	double b[dim],x0[dim],x[dim],soma,nmax;
	
	
	for(i=0; i<dim; i++)
	{
		x[i]=0;
		
		b[i] = M[i][dim];
	}
		
	do
	{
		nmax=0;
		
		for(i=0; i<dim; i++)
		
			x0[i] = x[i];
			
		for(i=0; i<dim; i++)
		{
			soma = 0.0;	
			
			for(j=0; j<dim; j++)
			{
				if(j!=i)
				
					soma=soma+(M[i][j]*x0[j]);
			}
		
			x[i] = (1/M[i][i]) * (b[i] - soma);
			
			nmax += fabs(x0[i]-x[i]) / fabs(x[i]);
		}
		
		c++;
					
	}while(nmax > 1e-5);
	
	
	printf("\nVetor B:\n");
	for(i=0; i<dim; i++)
	
		printf("%lf\t",b[i]);
	
	printf("\n");
	
	printf("\nVetor X:\n");
	for(i=0; i<dim; i++)
	
		printf("%lf\t",x[i]);
	
	printf("\n");
	
	printf("\nNúmero de iterações: %d\n\n",c);
}

	

int main(int qarg, char *arq[])
{

	int  y[3], p,lambida, soma=0, U, dim, l, c, d;
	FILE *in ;
	double **M, m ;
	
	in=fopen(arq[1], "r");
	l = fscanf(in, "%d", &dim);
     	
    M= malloc(dim*sizeof(double*));
	
	
	for(l=0; l<dim; l++)
	
	    M[l] = malloc((dim+1)*sizeof(double) );
	
	l = c = 0;
	while(fscanf(in, "%lf", &m) != EOF )
	{
		M[l][c] = m;
	    c++;
	        
	    if(c==dim+1)
	    {
		    c = 0;
	        l++;
	     }
	}
	
	printf("\nMatriz Completa:\n");
    imprime(M,dim);
	//procurando o elemento e trocando as linhas
	

	/*p = pivotamento(M,dim);
=======
	p = pivotamento(M,dim);
>>>>>>> efd6d13e9f07432720392144db308208c12a462e
	printf("\nMatriz Escalonada:\n");
	imprime(M,dim);
	
   // zerando a primeira coluna
    printf("\nDeterminante: ");
   	determinante(M,dim,p);
   	printf("\n");
     
    //Decomposição LU
    decomposicaoLU(M,dim);
    
    
    //Matriz inversa
<<<<<<< HEAD
    inversa(M,dim); */
    
    
    //Método de Jacobi
    jacobi(M,dim);

    fclose(in);
    
    return(0);
}

		
