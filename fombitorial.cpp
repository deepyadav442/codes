#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
long long int fun(long long intn,long long int m);
	int main()
	{
	long long int t,n,m,r,fnr,d,fr,fn,ans;
	int q;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%d",&n,&m,&q);
		long long int fn=fun(n,m);
		while(q--)
		{
			scanf("%lld",&r);
			 fr=fun(r,m);
			//printf("%lld\n",fr);
			 d=n-r;
			//printf("%lld\n",d);
			 fnr=fun(d,m);
			//printf("%lld\n",fnr);
			ans=(fn/(fr*fnr))%m;
			printf("%lld\n",ans);	
		}
	
	
	}
	return 0;
}
long long int fun(long long int n,long long int m)
{
	long long int i,j=1;
	for(i=1;i<=n;i++)
	{
		j=(j*pow(i,i));
		//printf("%lld%lld\n",i,j);
	}
	return j;
}
