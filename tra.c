#include<stdio.h>
void main()
{
int i,j,m,n,a[10][10],r[10][10];
printf("enter the order of the matrix\n");
scanf("%d%d",&m,&n);
printf("enter the matrix elements\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
r[i][j]=a[j][i];
}
}
printf("the transpose of matrix is\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d \t",r[i][j]);
}
printf("\n");
}
}
