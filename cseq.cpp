#include <bits/stdc++.h>
using namespace std;

const int sz = 1e9;
const long long mod = 1e9+7;

long long fact[sz];

long long _pow(int a, int b) {
    if(b == 0)
        return 1ll;
    long long ret = _pow(a, b/2);
    ret = (ret*ret) % mod;
    ret = (ret+mod)% mod;
    if(b%2 == 1)
        ret = (ret*a) % mod;
    ret = (ret+mod)% mod;
    assert(ret >= 0);
    assert(ret < mod);
    return ret;
}

long long inv(int a) {
    a%= mod;
    a = (a+mod)%mod;
    return _pow(a, mod-2);
}

int main()
{
    fact[0] = 1;
    for(int i = (int)1; i <= (int)sz-1; ++i) {
        fact[i] = (fact[i-1]*i) % mod;
    }
    int test;
    scanf("%d", &test);
    assert(test >= 1);
    assert(test <= 1e3);
    while(test--) {
        int n, m;
        cin >> n >> m;
        assert(1 <= n); assert(n <= 1e9);
        assert(1 <= m); assert(m <= 1e9);
        n--; m--;
        long long ans =  fact[n+m];
        ans = (ans*inv(fact[n])) % mod;
        ans = (ans + mod) % mod;
        ans = (ans*inv(fact[m])) % mod;
        ans = (ans + mod) % mod;
        assert(ans >= 0);
        assert( ans < mod);
        cout << ans << "\n";
    }

    return 0;
}
