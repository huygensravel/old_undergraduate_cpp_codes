 #include"vecteur.cpp"

 /*affectation d'une matrice*/
 void affectmati(int **,int **,int,int);
void affectmatf(float **,float **,int,int);

/*maximum des valeurs absolues des composantes*/
void maxmatf(float **A,int n,int p,float *max,int *nmax,int *pmax);
void maxmati(int **A,int n,int p,int *max,int *nmax,int *pmax);

/*produit de deux matrices*/
void entierprodmat(int,int**,int **,int,int);
void floatprodmat(float,float**,float **,int,int);

/*somme de deux matrices*/
void isummat(int**x,int**x1,int **y,int n,int);
void fsummat(float **x1,float**x,float **y,int n,int);

/*initialisation d'une matrice*/
int **imati(int n,int p);
float **imatf(int n,int p);

/*produit d'une matrice par un scalaire*/
void iprodmat(int k,int**x,int **y,int n,int p);
void fprodmat(float k,float**x,float **y,int n,int p);

/*lecture d'une matrice à l'écran*/
void entreemati(char *soratra,char *nomA,int **A,int n,int p);

/*affichage à l'écran d'une matrice*/
void sortiemati(char *soratra,char *nomA,int **A,int n,int p);
void sortiematf(char *soratra,char *nomA,float **A,int n,int p);
/*void main()
{
	int n;
	int **x;
	n=entreei("Donner la dimension : ");
	x=imati(n,n);
	if(x!=NULL)
	{
		entreemati("Donner une matrice ","A1",x,n,n);
		sortiemati("Vous avez entré : ","A1",x,n,n);
	}
} */


void entreemati(char *soratra,char *nomA,int **A,int n,int p)
{
	int i,j,t;
	printf("%s",soratra);

	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
	{
		printf("%s(%d)(%) = ",nomA,i,j);
		scanf("%d",&t);
		A[i][j]=t;
	}
}

void entreematf(char *soratra,char *nomA,float **A,int n,int p)
{
	int i,j;
	float t;
	printf("%s",soratra);
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
	{
		printf("%s(%d)(%d) = ",nomA,i,j);
		scanf("%f",&t);
		A[i][j]=t;
	}
}

float **imatf(int n,int p)
{
	int i,j;
	float **A;
	A=(float **)malloc(n*p*sizeof(float));
	if(A!=NULL)
	for(i=0;i<n;i++)
	{
		A[i]=(float *)malloc(p*sizeof(float));
		if(A[i]!=NULL)
		for(j=0;j<p;j++)
		{
			A[i][j]=0;
		}
	}
	return(A);
}

int **imati(int n,int p)
{
	int i,j;
	int **A;
	A=(int **)malloc(n*p*sizeof(int));
	if(A!=NULL)
	for(i=0;i<n;i++)
	{
		A[i]=(int *)malloc((p+1)*sizeof(int));
		if(A[i]!=NULL)
		for(j=0;j<p;j++)
		{
			A[i][j]=0;
		}
	}
	return(A);
}

void affectmati(int **x,int **y,int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
		{
			x[i][j]=y[i][j];
		}
}

void affectmatf(float **x,float **y,int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
		{
			x[i][j]=y[i][j];
		}
}

void maxmatf(float **A,int n,int p,float *max,int *nmax,int *pmax)
{
	int i,j,k=0,l=0;
	float m=fabs(A[0][0]);
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
		{
			if(m<fabs(A[i][j]))
			{
				m=fabs(A[i][j]);
				k=i;
				l=j;
			}
		}
	*max=m;
	*nmax=k;
	*pmax=l;
}

void maxmati(int **A,int n,int p,int *max,int *nmax,int *pmax)
{
	int i,j,k=0,l=0;
	int m=fabs(A[0][0]);
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
		{
			if(m<fabs(A[i][j]))
			{
				m=fabs(A[i][j]);
				k=i;
				l=j;
			}
		}
	*max=m;
	*nmax=k;
	*pmax=l;
}


void iprodmat(int k,int**x,int **y,int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			y[i][j]=k*x[i][j];
}

void fprodmat(float k,float**x,float **y,int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			y[i][j]=k*x[i][j];
}

void floatprodmat(float **x,float**y,float **z,int n,int q,int p)
{
	int i,j,k;
	float t;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			{
				for(k=0,t=0;k<q;k++)
					t=t+y[i][k]*x[k][j];
				z[i][j]=t;
			}
}

void entierprodmat(int **x,int**y,int **z,int n,int q,int p)
{
	int i,j,k;
	int t;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			{
				for(k=0,t=0;k<q;k++)
					t=t+y[i][k]*x[k][j];
				z[i][j]=t;
			}

}

void isummat(int**x,int**x1,int **y,int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			y[i][j]=x1[i][j]+x[i][j];
}

void fsummat(float **x1,float**x,float **y,int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			y[i][j]=x1[i][j]+x[i][j];
}

void permcolmat(float**x,float **y,int n,int p,int i1,int j1)
{
	int i;
	for(i=0;i<n;i++)
		{
			y[i][j1]=x[i][i1];
			y[i][i1]=x[i][j1];
		}
}

void permlinmat(float**x,float **y,int n,int p,int i1,int j1)
{
	int i;
	for(i=0;i<p;i++)
		{
			y[i1][i]=x[j1][i];
			y[j1][i]=x[i1][i];
		}
}

void sortiemati(char *soratra,char *nomA,int **A,int n,int p)
{
	int i,j;
	printf("%s \n",soratra);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
			printf("%d \t",A[i][j]);
		printf("\n");
	}
}

void sortiematf(char *soratra,char *nomA,float **A,int n,int p)
{
	int i,j;
	printf("%s \n",soratra);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
			printf("%f \t",A[i][j]);
		printf("\n");
	}
}
