#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<time.h>
int m,k,n;
int main()
{
printf("Entrer la dimension :\n");
scanf("%d",&m);

int **vect;

vect = new int*[m];



for (k = 0; k < m; k++)
{
randomize();
n=rand()%100;
vect[k]=&n;

 }
 clrscr();

	for (int i = 0; i < m; i++) {
		 printf("%d\n",vect[i]);
		 }

return 0;
}

