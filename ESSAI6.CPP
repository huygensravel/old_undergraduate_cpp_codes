#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>
#include<math.h>
void entreeint(float *a,int); /*lecture du vecteur*/
void entreedim(int *);
void sortieint(float *,int); /*affichage du vecteur*/
float *initvectint(int n);
void sommeint(float *,float *,float *, int);
float prodsca(float *,float *,int);
void max(float *,int);
void norme(float *,int);

void main()
{
	float *x,*y,*z,e;
	int k;

	entreedim(&k);
	clrscr();

	x=initvectint(k);
	y=initvectint(k);
	z=initvectint(k);

	entreeint(x,k);
		 clrscr();
	entreeint(y,k);
		 clrscr();
	 printf("norme du 1er vecteur =");
	norme(x,k);
	 printf("norme du 2eme vecteur =");
	norme(y,k);

	sommeint(x,y,z,k);

	sortieint(x,k);
	sortieint(y,k);
	 printf("somme =\b");
	sortieint(z,k);
	printf("\n");
	e=prodsca(x,y,k);
	printf("produit scalaire =%f\n",e);

	printf("max 1er vecteur=");
	  max(x,k);
	printf("max 2eme vecteur=");
	  max(y,k);
}

void entreeint(float *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("a(%d)",i);
		scanf("%f",&a[i]);
		printf("\n");
	}
}

void entreedim(int *n)
{
	printf(" Entrer la dimension : ");
	scanf("%d",n);
}

void sortieint(float *a, int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%f\n",a[i]);
	}
}

float *initvectint(int n)
{
	int i;
	float *a;
	a=(float *)malloc((n+1)*sizeof(float));
	if (a!=NULL)
	{
		for(i=0;i<n+1;i++)
		{
			a[i]=0;
		}
	}
	return(a);
}

void sommeint(float *a,float *b,float *c, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		c[i]=b[i]+a[i];
	}
}
float prodsca(float *a,float *b,int k)
{
 int i;
 float d;
	 d=0;
  for (i=0;i<k;i++)
 {
  d=d+a[i]*b[i];
  }
			 return(d);
}


void max(float *a,int k)
{
  int i;
  float max;
  max=a[0];
  for(i=0;i<k;i++)
  {
	if(a[i]<a[i+1])
	  max=a[i+1];
  }
  printf("%f",max);
  printf("\n");
}
void norme(float *a,int k)
{
 int i;
 float n;
 n=0;
 for(i=0;i<k;i++)
	{
		n=n+abs(a[i]);
	}
	printf("%f\n",n);
}
