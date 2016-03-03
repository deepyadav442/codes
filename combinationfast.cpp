#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000003
using namespace std;
vector<long long> f(100000001,1);
long long pow(int a,int b)
{
	long long x=1,y=a;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD;
		b /= 2;
	}
	return x;
}



long long InverseEuler(int n)
{
	return pow(n,MOD-2);
}

long long C(long long int n, long long int r)
{

	//for (int i=2; i<=n;i++)
	//	f[i]= (f[i-1]*i) % MOD;
	return (f[n]*((InverseEuler(f[r]) * InverseEuler(f[n-r])) % MOD)) % MOD;
}

void PreCompute()
{

	for (int i=2; i<=2000001;i++)
		f[i]= (f[i-1]*i) % MOD;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

	long long int t,m,n,ret,l;

	PreCompute();
//	ret=C(1000000+1000000-2,1000000-1);
	cin>>t;

	while(t--){

		cin>>m>>n>>l;

		cout<<(C(m+l-n+1,m)-1)<<endl;
	}

    return 0;
}
