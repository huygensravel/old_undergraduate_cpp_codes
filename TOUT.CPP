# include<math.h>
#include"matrix.cpp"

void transmat(float **b,float **a,int n);
void eqtriang(float **a,float *b,float *c,int n);
float testpivot(float**,int n);
void eqtriangsup(char*lettre,float **a,float*b,float *c,int n);/*c solution*/



void transmat(float **b,float **a,int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
	for(j=0;j<n;j++)
	{
		b[i][j]=a[j][i];
	}
  }

}

void eqtriang(char *lettre,float **a,float *b,float *c,int n)
 {
	 int i;int j;
	 float k;
	 k=0;
	 for(i=0;i<n;i++)
	 {

		 for(j=0;j<i;j++)
		 {
		 k=k+c[j]*a[i][j];
		 }

		c[i]=(b[i]-k)/a[i][i];
	 }

 printf("%s \n",lettre);

  sortief("","",c,n);

 }

 float testpivot(float **a,int n)
 {
		int i;
		float r;
		r=1;
		for(i=0;i<n;i++)
		 {
		  r=r*a[i][i];
		 }

				return(r);
 }
 void eqtriangsup(char*lettre,float **a,float*b,float *c,int n)
 {
	 int i;int j;
	 float k;

	 for(i=n-1;i>=0;i--)
	 {
			k=0;
		 for(j=i+1;j<n;j++)
		 {
		 k=k+c[j]*a[i][j];
		 }

		c[i]=(b[i]-k)/a[i][i];

	 }

	 printf("%s \n",lettre);

  sortief("","",c,n);

 }

