#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define mod 1000000007
typedef long long ll;
using namespace std;
inline ll input() //for input integers call it long long int n=input();
{
    ll n=0;
    char ch=getchar_unlocked();
    while( ch < '0' || ch > '9' )
    {
        ch=getchar_unlocked();
    }
    while( ch >= '0' && ch <= '9' )
    {
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    }
    return n;
}
inline void output(ll n)     //for output call output(count) and then for space use put('\n');
{
    char b[35];
    ll i=0;
    do
    {
        b[i++]=n%10+48;
        n=n/10;
    }while(n!=0);
    --i;
    while(i>=0)
    putchar_unlocked(b[i--]);
}
inline void faststring(char *str)  //for entering a string use faststring(p);
{
    register char c = 0;
    register long long i = 0;
    while (c < 33)
    c = getchar_unlocked();
    while (c != '\n')
    {
        str[i] = c;
        c = getchar_unlocked();
        ++i;
    }
    str[i] = '\0';
}
int main()
{
	ll t,n,i;
	t=input();
	while(t--)
	{
		ll xor1=0,xor2=1,v;
		n=input();
		for(i=0;i<n-1;i++)
		{
			v=input();
			xor1^=v;
		}
		for(i=2;i<=n;i++)
			xor2^=i;
		//sum2=(n*(n+1))/2;
		//sum2-=sum1;
		printf("%lld\n",(xor1^xor2));
	}
return 0;
}
