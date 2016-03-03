#include<cstdio>
#include<iostream>
using namespace std;
long modPow(long a, long x, long p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long modInverse(long a, long p) {
    return modPow(a, p-2, p);
}
long modBinomial(long n, long k, long p) {
    long numerator = 1;
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long int mod=1000003;
            long int n,l,r;
            scanf("%ld%ld%ld",&n,&l,&r);
            printf("%ld\n",modBinomial((n+r-l+1),n,mod)-1);
        }

}





