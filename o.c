#include<stdio.h>
void main()
{
int sum=0,i,d,c=0;
printf("enter the number ");
scanf("%d",&d);
for(i=1;i<1000;i++)
{
if(i%2!=0)
{
printf("the number is %d",i);
sum=sum+i;
c++;
}
if(c==d)
{
printf("%d",sum);
break;
}
}
}


