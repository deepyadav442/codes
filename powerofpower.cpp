#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	long long t,i,a,b;
	long double m;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld%lld",&a,&b);		
		m=pow(a,b);
		long double sum=0,rem=0;
		while(m!=0)
		{
			rem=m%((long double)(10));
			sum=sum+rem;
			m=m/10;
		}
	long long ans=(long long)(sum);
	printf("Case %lld:%lld\n",i,ans);
	}
	return 0;
}

