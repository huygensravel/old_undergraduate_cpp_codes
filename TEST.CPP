#include "triang~1.cpp"
void transmat(float **b,float **a,int n);

/*void main()
{
	 int n;
	 float **a,**b;
	 n=entreei("donner la dimension :");
	 a=imatf(n,n);
	 b=imatf(n,n);
	 entreematf(" "," ",a,n,n);
	 transmat(b,a,n);
	 sortiematf(" "," ",b,n,n);
} */

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
