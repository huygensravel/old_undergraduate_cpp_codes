#include <time.h>
#include "tringsup.cpp"
//void symvect(float*,float*,int);
void gauss(float **a,float*c,int n);

void main()
{
	int n; //int k,i,j;
	float *c;
	float *d;
	float **a;

			 printf("\t\t\tMETHODE DE GAUSS SANS PERMUTATION\n");
			 printf("\t\t\t\________________________________\n\n");


	n=entreei("donner la dimension :");
	a=imatf(n,n);
	c= ivectf(n);
	d=ivectf(n);

	/*randomize();
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	a[i][j]=random(10);
	for(k=0;k<n;k++)
	c[k]=random(10); */
	entreematf("donner la matrice","A",a,n,n);

entreevectf("donner le vecteur second membre","\t b",c,n);
		printf("\n");
	  sortiematf("matrice initiale","",a,n,n);
		printf("\n");


	if(testpivot(a,n)!=0)
	 {
	  gauss(a,c,n);
	 }

	eqtriangsup(a,c,d,n);
}


/*void symvect(float*c,float *symc,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		  symc[n-i-1]=c[i];
	}


} */

void gauss(float**a,float*c,int n)
{
	  int i,j,k;
	  float **x;
	  float r;
	  x=imatf(n,n);
	  r=0;

	  for(k=0;k<n;k++)
	  {
			  printf("étape %d",k+1);

			 if(a[k][k]!=0)
			 {
			  for(i=k+1;i<n;i++)
			  {
					  r=a[i][k]/a[k][k];
					  c[i]=c[i]-r*c[k];

				  for(j=k;j<n;j++)
				  {
					 a[i][j]=a[i][j]-r*a[k][j];
				  }
			  }

				affectmatf(x,a,n,n);
			  sortiematf("matrice\n","A",x,n,n); sortief("","",c,n);
			  }
			  else
			  {
				 exit(0);
			  }

			  affectmatf(a,x,n,n);
	  }

}

