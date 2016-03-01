#include<stdio.h>
#include<stdlib.h>
int quicksort(int x[],int first,int last);
int main()
{
	int t,i,j,n;
	int a[1000001];
	long long temp;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		quicksort(a,0,n-1);
		temp=a[n-1]+a[n-2]+a[n-3];
		printf("Case %d: %lld\n",i,temp);
	}
	return 0;
}






int quicksort(int x[],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}
