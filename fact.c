#include<stdio.h>
void main()
{
int  n,fact;
printf("enter the number\n");
scanf("%d",&n);
fact=factorial(n);
printf("%d",fact);
}
int factorial(int n)
{
int fact;
if(n==0||n==1)
{
return(1);
}
else
{
fact=n*factorial(n-1);
return(fact);
}
printf("\n");
}

