#include<stdio.h>
int main(){
  int a[100][100],i,j,n;
  float determinant=0;
   scanf("%d",&n);
  printf("Enter the 9 elements of matrix: ");
  for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         {
             if(i==j)
                a[i][j]=0;
             else
                a[i][j]=1;
         }

  printf("\nThe matrix is\n");
  for(i=0;i<n;i++){
      printf("\n");
      for(j=0;j<n;j++)
           printf("%d\t",a[i][j]);
  }
  for(i=0;i<n;i++)
      determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
   printf("%f",determinant);
   printf("\nInverse of matrix is: \n\n");
   for(i=0;i<n;i++){
      for(j=0;j<n;j++)
           printf("%.2f\t",((a[(i+1)%n][(j+1)%n] * a[(i+2)%n][(j+2)%n]) - (a[(i+1)%n][(j+2)%n]*a[(i+2)%n][(j+1)%n]))/ determinant);
       printf("\n");
   }

   return 0;
}
