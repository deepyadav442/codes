#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int t,n,k,i,a[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int x,y,j,temp,max=0;
		for(i=0;i<n-1;i++)
		{
			x=a[i];
			for(j=i+1;j<n;j++)
			{
				temp=x^a[i];
				printf("%d",temp);
				if((temp^k)>=max)
					max=temp^k;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
