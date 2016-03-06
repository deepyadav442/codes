// counting the number of perfect squares from 1 to n is prime or not n=10^9
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&b);
        ll i=1,k=sqrt(b);
        ll count=0;
        for (ll n = i*i; i <= k; i++)
            count++;
        int flag=0;
        for(i=2;i<=sqrt(count);i++)
        {
            if((count%i)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("silver ball is selected.\n");
        else
            printf("golden ball is selected.\n");

    }
    return 0;
}
