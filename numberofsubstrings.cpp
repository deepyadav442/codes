#include<cstdio>
#include<iostream>
int main()
{
    long long n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        char a[n];
        scanf("%s",a);
        long long i,num=0;
        for(i=0;i<n;i++)
        {
            if(a[i]=='1')
                num++;
        }
        printf("%lld\n",(num*(num+1)/2));
    }
    return 0;
}
