#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define mod 1000000007
typedef long int ll;
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
int flag=0;
void primeFactors(ll n)
{
    while (n%2 == 0)
    {
        n = n/2;
    }
    for(int i = 3; i <=sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            if(((i-1)%4)==0)
            {
                flag=1;
                return;
            }
            n = n/i;
        }
    }
    if (n > 2)
        {
           if(((n-1)%4)==0)
            {
                flag=1;
                return;
            }
        }
}
int main()
{
    ll t,n;
    t=input();
    while(t--)
    {
        flag=0;
        n=input();
         primeFactors(n);
         if(flag==0)
            printf("NO\n");
         else
            printf("YES\n");
    }
    return 0;
}
