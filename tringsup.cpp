#include"matrix.cpp"

void eqtriangsup(float **a,float*b,float *c,int n);/*c solution*/
float testpivot(float**,int n);
/*void main()
{
 float **a;
 float *b;
 float *c;
 int n;
	 n=entreei("donner la dimension :");

	 a=imatf(n,n);
	 b= ivectf(n);
	 c=ivectf(n);
	 entreematf("donner une matrice triangulaire supérieure","A",a,n,n);
	 sortiematf("matrice ","A",a,n,n);
	 entreevectf("donner le vecteur second membre","\t b",b,n);
		  clrscr();
	 if(testpivot(a,n)!=0)
	 eqtriangsup(a,b,c,n);
} */

void eqtriangsup(float **a,float*b,float *c,int n)
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

  sortief("voici la solution"," ",c,n);

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