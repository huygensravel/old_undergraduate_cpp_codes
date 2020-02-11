#include"matrix.cpp"

void eqtriang(float **a,float *b,float *c,int n);
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
	 entreematf("donner une matrice triangulaire inférieure","A",a,n,n);
	 sortiematf("matrice ","A",a,n,n);
	 entreevectf("donner le vecteur second membre","\t b",b,n);
		  clrscr();
	 if(testpivot(a,n)!=0)
	 eqtriang(a,b,c,n);
} */

void eqtriang(float **a,float *b,float *c,int n)
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

  sortief("voici la solution","",c,n);

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
