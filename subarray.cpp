#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define mod 1000000007
typedef long long int ll;
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
    ll t,n,i,j;
    t=input();
    while(t--)
    {
        n=input();
	ll arr[100001],count=0;
	for(i=0;i<n;i++)
		arr[i]=input();
	if(n==1)
	{
		printf("1\n");
		continue;
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n-1;j++)
		{
			if(arr[j+1]>=arr[j])
				count++;
			else
				break;
		}
	}
	printf("%lld\n",count+n);
     }
    return 0;
}
