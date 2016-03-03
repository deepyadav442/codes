#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
#define MOD 1000000007
using namespace std;

typedef long long ll;

// B1 and B2 are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
ll B1[100005], B2[100005];

// Array size
int N;

// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b]%MOD;
	return sum;
}
// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void updateadd(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v%MOD;
}

// Range update: Adds v to each element in [i...j]
void range_updateadd(int i, int j, ll v)	{
	updateadd(B1, i, v);
	updateadd(B1, j + 1, -v);
	updateadd(B2, i, v * (i - 1));
	updateadd(B2, j + 1, -v * j);
}
void updatemultiply(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k))
        ft[k] *= v%MOD;
}

// Range update: Adds v to each element in [i...j]
void range_updatemultiply(int i, int j, ll v)	{
	updatemultiply(B1, i, v);
	updatemultiply(B1, j + 1, -v);
	updatemultiply(B2, i, v * (i - 1));
	updatemultiply(B2, j + 1, -v * j);
}
void updateinit(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k))
        ft[k]= v%MOD;
}

// Range update: Adds v to each element in [i...j]
void range_updateinit(int i, int j, ll v)	{
	updateinit(B1, i, v);
	updateinit(B1, j + 1, -v);
	updateinit(B2, i, v * (i - 1));
	updateinit(B2, j + 1, -v * j);
}
int main()  {
	int T, C, p, q, cmd;
	ll v;
		// C -> No. of operations
		scanf("%d %d",&N,&C);
		for(int i=1;i<=N;i++)
        {
            scanf("%lld",&B1[i]);
            B2[i]=B1[i];
        }
		//memset(B1, 0, (N+1) * sizeof(ll));
		//memset(B2, 0, (N+1) * sizeof(ll));
		while (C--)	{
                    scanf("%d",&T);
                    if(T==1)
                    {
                        scanf("%d %d %lld",&p,&q,&v);
                        range_updateadd(p, q, v);
                    }
                    if(T==2)
                    {
                        scanf("%d %d %lld",&p,&q,&v);
                        range_updatemultiply(p,q,v);
                    }
                    if(T==3)
                    {
                        scanf("%d%d%lld",&p,&q,&v);
                        range_updateinit(p,q,v);
                    }
                    else
                    {
                        scanf("%d%d",&p,&q);
                        printf("%lld\n", range_query(p,q));
                    }
		           }

    return 0;
}
