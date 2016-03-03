#include<cstdio>
#include<iostream>
#define mod 1000000007
long long gcd(long long a,long long b);
long long fibo(long long p);
long long ackFib (long long n, long long m, long long count);
int main()
{
long long t;
scanf("%lld",&t);
while(t--)
{
long long a,b;
 scanf("%lld%lld",&a,&b);
long long p=gcd(a,b);
long long ans=fibo(p);
printf("%lld\n",ans%mod);
}
return 0;
}
long long gcd(long long a,long long b)
{
if(b==0)
    return a;
else
    return gcd(b,a%b);
}
void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);

long long fibo(long long n)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power(F, n-1);

  return F[0][0];
}

void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long long F[2][2], long long n)
{
  long long i;
  long long M[2][2] = {{1,1},{1,0}};
  for (i = 2; i <= n; i++)
      multiply(F, M);
}
