#include<stdio.h>
 main(){
int arr[10][10],size,i,j,temp;
printf("\n enter the size of matrix");
scanf("%d",&size);
printf("\n enter the values a:");
for(i=0;i<size;i++){
for(j=0;j<size;j++){
scanf("%d",&arr[i][j]);
}
}
printf("\n given square matrix is");
for(i=0;i<size;i++){
printf("\n");
for(j=0;j<size;j++){
printf("%d\t",arr[i][j]);
}
}
for(i=1;i<size;i++){
for(j=0;j<i;j++){
temp=arr[i][j];
arr[i][j]=arr[j][i];
arr[j][i]=temp;
}
}
printf("\n transpose matrix is:");
for(i=0;i<size;i++);
printf("\n");
for(j=0;j<size;j++){
printf("%d\t",arr[i][j]);{
}
}
