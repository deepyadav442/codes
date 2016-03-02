#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll t,m,i;
	double p;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lf",&m,&p);
		if(m==1||p==0.00)
		{
			printf("1000000000.00 0.00\n");
			continue;
		}
		if(p==1.0000)
		{
			if(m&1)
				printf("1000000000.00 0.00\n");
			else
				printf("0.00 0.00\n");
			continue;
		}		
		double r=pow((-p),(m-1));
		double z=((-p)*(r-1))/(-1-p)+1.00;
		double y=z*1000000000.000;
		double cv=1000000000.00-y;
		printf("%.2lf %.2lf\n",cv,y);
	}
	return 0;
}
