#include <bits/stdc++.h>
int a[100001];
using namespace std;
int f1(int* a)
{
char c=0;
while (c<33)
c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
return 0;
}

long long int f2(long long int* a)
{
char c=0;
while (c<33)
c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
return 0;
}
pair<long long int,long long int> chain[501000];
long long int md;
vector<long long int>seive;
long long int ind[101000];
long long int rptsqr_pow(long long int x,long long int n){
long long int fn=1;
while(n>0){
    if(n&1)fn=fn*x;//if(n&1)fn=fn*x;
      x=     //x=x*x;
           //x%=md;
           //fn%=md;
           //n/=2;}
return fn;
}
long long int cnt=0;
void build(long long int node,long long int l,long long int r,long long int pos,long long int val){
if(l==r){
chain[node].first+=val;
chain[node].second=rptsqr_pow(seive[l],chain[node].first);
return;
}
long long int m=(l+r)/2;
if(pos<=m) build(2*node,l,m,pos,val);
else build(2*node+1,m+1,r,pos,val);
chain[node].second=((long long int)chain[2*node].second*(long long int)chain[2*node+1].second)%md;

}
long long int p[101000];
long long int idx_size[101000];

long long int fn[101000];
int main(){
memset(a,0,sizeof(a));
p[1]=1;
seive.push_back(1);
idx_size[1]=1;
for(int i=2;i<=100000;i++){
idx_size[i]=idx_size[i-1];
if(p[i]==0){
idx_size[i]++;
seive.push_back(i);
for(long long int j=i;j<=100000;j+=i){
p[j]=i; }
}
}
for(int i=0;i<seive.size();i++){
idx_size[seive[i]]=i;
}
idx_size[seive[0]]=1;
long long int t,n,r,q;
f2(&t);
while(t--){
f2(&n);
f2(&md);
f2(&q);
for(long long int i=0;i<=4*idx_size[n];i++){
chain[i].first=0;
chain[i].second=1;
}
for(int i=n;i>=(n+1)/2;i--){
long long int h=i;
r=n+1-i;
if(r>i) break;
while(p[h]>1){
build(1,1,idx_size[n],idx_size[p[h]],i);
h/=p[h];
}
h=r;
while(p[h]>1){
build(1,1,idx_size[n],idx_size[p[h]],-r);
h/=p[h];
}
fn[n-r]=chain[1].second;
fn[r]=chain[1].second;
}
for(int i=0;i<q;i++){
f2(&r);
printf("%lld\n",fn[r]);
}
}
}
