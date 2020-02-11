#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

/*dans tout ce qui suit les arguments char permettront à l'utilisateur
de la fonction d'insérer des commentaires ou des notations*/

int entreei(char *); /*lecture d'un entier*/
float entreef(char *);/*lecture d'un flotant*/
void entreevecti(char *,char*,int *,int);/*lecture d'un vecteur entier*/
void entreevectf(char *,char*,float *,int);/*lecture d'un vecteur flotant*/
float * ivectf(int);/*initialisation de vecteur flotant*/
int * ivecti(int);  /*initialisation de vecteur entier*/
void sortief(char *,char*,float *,int);/*sortie d'un vecteur flotant*/
void sortiei(char *,char*,int *,int);  /*sortie d'un vecteur entier*/
void affectvecti(int *,int *,int); /*affectation de vecteur entier*/
void affectvectf(float *,float *,int); /*affectation de vecteur flotant*/

/*recherche du maximum d'un vecteur*/
void maxf(float *,int,float *,int *);
void maxI(int *,int,int *,int *);
/*produit par un scalaire*/
void entierprodvect(int,int*,int *,int);
void fprodvect(float,float*,float *,int);
/*somme de deux vecteurs*/
void isumvect(int*x,int*x1,int *y,int n);
void fsumvect(float *x1,float*x,float *y,int n);
/*produit scalaire de deux vecteurs*/
float fprodscal(float*x,float *y,int n);
int iprodscal(int*x,int *y,int n);

/*void main()
{
	int n,k,m;
	int *x;
	n=entreei("Donner la dimension : ");
	x=ivecti(n);
	if(x!=NULL)
	{
		entreevecti("Donner un vecteur ","A1",x,n);
		sortiei("Vous avez entré : ","A1",x,n);
		maxI(x,n,&m,&k);
		printf("\n max = %d, rang = %d",m,k);
	}
}*/



int entreei(char *soratra)
{
	int n;
	printf("%s",soratra);
	scanf("%d",&n);
	return(n);
}

float entreef(char *soratra)
{
	float x;
	printf("%s",soratra);
	scanf("%f",&x);
	return(x);
}

void entreevecti(char *soratra,char *nomA,int *A,int n)
{
	int i;
	printf("%s",soratra);
	for(i=0;i<n;i++)
	{
		printf("%s(%d) = ",nomA,i);
		scanf("%d",&A[i]);
	}
}

void entreevectf(char *soratra,char *nomA,float *A,int n)
{
	int i;
	printf("%s",soratra);
	for(i=0;i<n;i++)
	{
		printf("%s(%d) = ",nomA,i);
		scanf("%f",&A[i]);
	}
}

float *ivectf(int n)
{
	int i;
	float *A;
	A=(float *)malloc(n*sizeof(float));
	if(A!=NULL)
	for(i=0;i<n;i++)
	{
		A[i]=0;
	}
	return(A);
}

int * ivecti(int n)
{
	int i;
	int *A;
	A=(int *)malloc(n*sizeof(int));
	if(A!=NULL)
	for(i=0;i<n;i++)
	{
		A[i]=0;
	}
	return(A);
}

void sortief(char *soratra,char *nomA,float *A,int n)
{
	int i;
	printf("%s \n",soratra);
	for(i=0;i<n;i++)
	{
		printf("%s(%d) = %f\n",nomA,i,A[i]);
	}
}

void sortiei(char *soratra,char *nomA,int *A,int n)
{
	int i;
	printf("%s \n",soratra);
	for(i=0;i<n;i++)
	{
		printf("%s(%d) = %d\n",nomA,i,A[i]);
	}
}

void affectvecti(int *x,int *y,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		x[i]=y[i];
	}
}

void affectvectf(float *x,float *y,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		x[i]=y[i];
	}
}

void maxf(float *A,int n,float *max,int *kmax)
{
	int i,k=0;
	float m=fabs(A[0]);
	for(i=1;i<n;i++)
	{
		if(m<fabs(A[i]))
		{
			m=fabs(A[i]);
			k=i;
		}
	}
	*max=m;
	*kmax=k;
}

void maxI(int *A,int n,int *max,int *kmax)
{
	int i,k=0;
	int m=abs(A[0]);
	for(i=1;i<n;i++)
	{
		if(m<abs(A[i]))
		{
			m=abs(A[i]);
			k=i;
		}
	}
	*max=m;
	*kmax=k;
}

void entierprodvect(int k,int*x,int *y,int n)
{
	int i;
	for(i=0;i<n;i++)
		y[i]=k*x[i];
}

void fprodvect(float k,float*x,float *y,int n)
{
	int i;
	for(i=0;i<n;i++)
		y[i]=k*x[i];
}

void isumvect(int*x,int*x1,int *y,int n)
{
	int i;
	for(i=0;i<n;i++)
		y[i]=x1[i]+x[i];
}

void fsumvect(float *x1,float*x,float *y,int n)
{
	int i;
	for(i=0;i<n;i++)
		y[i]=x1[i]+x[i];
}

float fprodscal(float*x,float *y,int n)
{
	int i;
	float w=0;
	for(i=0;i<n;i++)
		w+=y[i]*x[i];
	return(w);
}

int iprodscal(int*x,int *y,int n)
{
	int i;
	int w=0;
	for(i=0;i<n;i++)
		w+=y[i]*x[i];
	return(w);
}

void ipermvect(int*x,int *y,int n,int i1,int j)
{
	int i;
	int w=x[i1],w1=y[j];
	for(i=0;i<n;i++)
		{
			if (i==i1)y[i]=w1;
			 else
				if (i==j) y[i]=w; else y[i]=x[i];
		}
}
