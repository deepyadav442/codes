#include<bits/stdc++.h>
typedef long long ll;
ll calculate(ll number)
{
    ll result[]={number,1,number+1,0};
    return result[number%4];
}
ll XOR(ll a,ll b)
{
    return calculate(b)^calculate(a-1);
}
int main()
{
    int q;
    ll a,b;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld%lld",&a,&b);
        ll ans=XOR(a,b);
        printf("%lld\n",ans);
    }
    return 0;
}
