#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,a[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d",a[i][j]);
			}
		printf("  \n");
	}
	
	int sum2=0,sum1=0;
	for(i=0,j=0;i<n&&j<n;i++,j++)
		sum1+=a[i][j];
	for(i=0,j=n-1;i<n&&j>=0;i++,j--)
		sum2+=a[i][j];
	cout<<"difference is\n";	
	printf("%d",abs(sum1-sum2));
	return 0;
}
