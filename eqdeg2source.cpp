#include<stdio.h>
#include<math.h>

void entree(float &a,float &b,float &c);
void solve(float &a,float &b,float &c);
void equation1erdeg(float &a,float &b);
float determinant(float &a,float &b,float &c);
void equation2nddeg(float &a,float &b,float &c);
void complexsolv(float &a,float &b,float &c);

int main()
{
  float a,b,c;
  printf("\t\tRESOLUTION D'UNE EQUATION DE DEGREE 1 OU 2\n");
  printf("\t\t__________________________________________\n\n");
 
  entree(a,b,c);
  solve(a,b,c);
  return 0 ;
  
}


void entree(float &a,float &b,float &c)
{

     printf("entrer le coeficient de x^2\t");
	 scanf("%f",&a);
     printf("entrer le coeficient de x\t");
	 scanf("%f",&b);
     printf("entrer la constante \t");                                                                                                                                                                                                                       
	 scanf("%f",&c);      

}


void solve(float &a,float &b,float &c)
{


        if(a==0)
	 {
		  if(b==0)
		  {
			 if(c==0)
			 {
				printf("tout reelle est solution");
			 }
			 else
			 {
				printf("pas de solution");
			 }
		  }
		  else
		  {
		  equation1erdeg(b,c);
		  }
	 }
	 else
	 {
			equation2nddeg(a,b,c);
	 }



}



void equation1erdeg(float &b,float &c)
{
  float x;
  x=-c/b;
  printf("on a la solution\t %f",x);
}




float determinant(float &a,float &b,float &c)
{
  float det;
  det=b*b-4*a*c;
  return det;
}



void equation2nddeg(float &a,float &b,float &c)
{
  float x1,x2,det;
  det=determinant(a,b,c);
  if(det==0)
  {
	 x1=-b/(2*a);
	 printf("on a une racine double \t %f",x1);
  }
  else
  {
		if(det>0)
		{
		 x1=(-b+sqrt(det))/2*a;
		 x2=(-b-sqrt(det))/2*a;
		 printf("les deux racines sont \t %f \t %f",x1,x2);
		}
		else

               complexsolv(a,b,c);
		  
  }
}


void complexsolv(float &a,float &b,float &c)
{

          float det,x1,x2;
          det=determinant(a,b,c);
          x1=-b/(2*a);
	  x2=sqrt(-det)/(2*a);
	  printf("les deux racines sont \t ");
	  printf("%f+i%f\t",x1,x2);
 	  printf("%f-i%f\t",x1,x2);
}                                                        
