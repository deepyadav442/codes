#include<bits/stdc++.h>
using namespace std;
int prime_check(long int n)
{
    long int i,k;
    for(i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
            return 1;
    }
    return 0;
}
long int check(long int n)
{
    long int i,j;
    for(i=n/2;i>0;i--)
    {
        if(n%i==0)
        {
            long int j=prime_check(i);
            if(j==0)
                return i;
        }
    }
}
int main()
{
    int t;
    long int n;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        scanf("%ld",&n);
        while(n!=2){
        long int n=check(n);
        count++;
        }
        printf("%d\n",count+1);
    }
    return 0;
}
