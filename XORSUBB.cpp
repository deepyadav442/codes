#include <bits/stdc++.h>
using namespace std;
namespace SUBBXOR {
struct Node {
  Node* ch[2];
  int cnt;
 
};
 
typedef long long ll;
typedef Node* pNode;
pNode root;
int a[300005];
 
pNode alloc() {
  pNode p = new Node();
  p->ch[0] = p->ch[1] = NULL;
  p->cnt = 0;
  return p;
}
 
void add(const int x) {
  pNode at = root;
  for (int b = 31; b >= 0; b--) {
    const int nx = (x >> b & 1);
    if (!at->ch[nx])
      at->ch[nx] = alloc();
  //  at->cnt++;
    at = at->ch[nx];
  }
//  at->cnt++;
}
 
int go(const int x) {
  pNode at = root;
  int res = x;
  int p=1;
  for ( int b = 31; b >= 0 && at; b--) {
  	int y=x >> b & 1;
  	//cout<<x<<" "<<y<<'\n';
  //	y=1-y;
  		//cout<<at->ch[y];
  	if(at->ch[y]!=NULL)
  	{
  		//cout<<"In "<<y<<"\n";
  		at=at->ch[y];
  		
  		
  	}
  	else
  	{
  			//cout<<"Other "<<1-y<<"\n";
  		at=at->ch[1-y];
  		{
  			
  				//cout<<"X is "<<x<<" Res is "<<res<<" b is "<<b<<" ~b is "<<(~(1<<b))<<endl;
  			res=res ^ (y<<b);
  			//cout<<"X is "<<x<<" Res is "<<res<<endl;
  		}
 
  	}
  	//cout<<"Res is "<<res<<"\n";
  }
 
  return res;
}
 
void solve(int test_num) {
  int N, K;
  cin >> N ;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  root = alloc();
  add(0);
  int xsum = 0;
  ll res = 0;
  ll maxx=0;
  ll count=0;
    add(a[1]);
  for (int i = 2; i <= N; i++) {
    xsum ^= a[i];
    res += go(xsum);
    res=go(a[i]);
    //cout<<"a[i] is "<<a[i]<<" Res is "<<res<<endl;
    //cout<<res<<" "<<a[i]<<"\n";
    //printf("%lld")
    //cout<<res<<"\n";
    if(res==0)
    	count+=res*2;
    if(res>maxx)
    maxx=res;
 
    //pln(i, res);
    //dbgln(xsum);
    add(a[i]);
    add(xsum);
  }
  cout << maxx << endl;
}
 
void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}
 
int main() {
  SUBBXOR::solve(1);
  return 0;
}
