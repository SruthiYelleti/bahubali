#include<stdio.h>
#include<math.h>
int main()
{
int a,b,c;
float x,y,d;
printf("enter a,b,c of quadratic equation\n");
scanf("%d%d%d",&a,&b,&c);
d=(b*b-4*a*c);
if(d<0)
{
printf("real roots does not exist\n");
}
x=-b+sqrt(d)/2*a;
y=-b-sqrt(d)/2*a;
printf("the roots of the quadratic equation are%f %f\n",x,y);
}

