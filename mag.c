 n     #include<stdio.h>
#include<math.h>
void main()
{
int a,b,c=0,d,e,f=0,n;
printf("enter a number");
scanf("%f",&n);
a=n*n;
for(i=1;i<=n;i++)
{
b=a%10;
a=a/10;
c=(c*10)+b;
}
d=sqrt(c);
for(i=1;i<=c;i++)
{
e=d%10;
e=d/10;
f=(f*10)+c;
}
if(f==n)
printf("magic numbers");
}

