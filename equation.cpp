 /*                                  deepyadav442 --> :     c++14     <--                                */
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
/*                                           input                    */
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d%d",&i,&j)
#define siii(i) scanf("%lld",&i)
#define sss(s) scanf("%s",s)
/*                                           output                   */
#define pi(i) printf("%d",i)
#define pii(i,j) printf("%d%d",i,j)
#define piii(i) printf("%lld",i)
#define space printf(" ")
#define newline printf("\n")
/*                                          loops &stls                      */
#define loop(i,s,n) for(i=s;i<n;i++)
#define looprev(i,s,n) for(i=s;i>=n;i--)
#define itervec vector<int>::iterator itv
#define iterrev vector<int>::reverse_iterator it
#define itermap map<string,int>::iterator itm
#define pb(S) push_back(S)
#define mp(i,j) make_pair(i,j)
#define f first
#define s second
#define MAX(a,b) 	(a>b) ? (a) : (b)
#define MIN(a,b) 	(a<b) ? (a) : (b)
using namespace std;
int cnt=-1;
ll combination(ll n)
{
	if(n<0)
		return 0;
	n = ((n+1)*(n+2)*(n+3))/6;
	return n;
}
int main()
{
	int t;
	si(t);
	while(t--){
		ll a,b,c,n;
		siii(n),siii(a),siii(b),siii(c);
		ll ans=combination(n)-combination(n-a-1)-combination(n-b-1)-combination(n-c-1)+combination(n-a-b-2)+combination(n-a-c-2)+combination(n-b-c-2)-combination(n-a-b-c-3);
		piii(ans);
		newline;	
			
	}
	return 0;
}
