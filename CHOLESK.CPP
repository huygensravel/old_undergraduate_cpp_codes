#include"tout.cpp"

 void cholesky1(float**matriceinitiale,float**resultat,int);

 void main()
 {

		int n;
		float *b,*y,*x;
		float**a,**l,**transl;

			printf("\t\t\tMETHODE DE CHOLESKY\n");
			 printf("\t\t\t\___________________\n\n");

	n=entreei("donner la dimension :");
	printf("\n");
	a=imatf(n,n);
	l=imatf(n,n);
	transl=imatf(n,n);

	b=ivectf(n);
	y=ivectf(n);
	x=ivectf(n);
	entreematf("donner la matrice\n","A",a,n,n);
	entreevectf("donner le vecteur second membre\n","\t b",b,n);
	cholesky1(a,l,n);
	sortiematf("","L",l,n,n);
	transmat(transl,l,n);
	eqtriang("solution 1",l,b,y,n);
	eqtriangsup("solution finale",transl,y,x,n);

  }

void  cholesky1(float**a,float**l,int n)
{
	 int m,i,j,k,p;
	 float r,c,s;
				l[0][0]=sqrt(a[0][0]);
				for(i=0;i<n;i++)
				{
					 l[i][1]=a[i][1]/a[1][1];

					 for(k=1;k<n-1;k++)
					 {
							  c=0;
							for(j=0;j<k-1;j++)
							 {
								 c=c+a[k][j]*a[k][j];
							 }

							l[k][k]=sqrt(a[k][k]-c);

							for(m=k+1;m<n;m++)
							 {
								 r=0;
								 for(j=0;j<k-1;j++)
									{
									  r=r+a[m][j]*a[k][j];
									}

								l[m][k]=(a[m][k]-r)/a[k][k];
							 }
					  }
				 }


				 s=0;
			 for(p=0;p<n-1;p++)
				{
				  s=s+a[n-1][p]*a[n-1][p];
				}

				l[n-1][n-1]=sqrt(a[n-1][n-1]-s);
}
