#include<stdio.h>
void main()
{
int x,y,temp;
printf("enter the values of x,y\n");
scanf("%d %d",&x,&y);
printf("before swaping\nx=%d\ny=%d\n",x,y);
temp=x;
x=y;
y=temp;
printf("after swaping\nx=%d\ny=%d\n",x,y);
}
