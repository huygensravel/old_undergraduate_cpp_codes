#include<stdio.h>
int main()
{
    int n;
    int factoriel(int i);
    printf("ce programme calcul le factoriel d'un entier\n\t");
    printf("entrer l'entier\b");
    scanf("%d",&n);
    printf("voici le résultat %n",n=factoriel(n));
    return(0);
   
}

int factoriel(int i)
{
    if(i>1)
        return(i=i*factoriel(i-1));
    else
        return(1);
              
}
