#include<iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>
#include<math.h>
#include<cstring>
#include<cstdio>
#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)
using namespace std;

int arr[100005];

int gcd(int a,int b)
{
	if(a==1000000000 )  return b;
	if(b==1000000000)  return a;
	if(a==0)    return b;
	else		return gcd(b%a,a);
}

int createsegtree1(int *stree1,int ss,int se,int idx)
{
	if(ss==se)
	{
		stree1[idx]=arr[ss];
		return stree1[idx];
	}

	int mid=(ss+se)/2;

	int x=createsegtree1(stree1,ss,mid,2*idx+1);
	int y=createsegtree1(stree1,mid+1,se,2*idx+2);

	stree1[idx]=max( x,y );

	return stree1[idx];
}

int rmaxq(int *stree1,int ss,int se,int q1,int q2,int idx)
{
	if(ss>=q1 && se<=q2)
		return stree1[idx];

	if(q1>se || q2<ss)
		return 0;

	int mid=(ss+se)/2;

	int x=rmaxq(stree1,ss,mid,q1,q2,2*idx+1);
	int y=rmaxq(stree1,mid+1,se,q1,q2,2*idx+2);

	return max(x, y) ;


}

int createsegtree2(int *stree2,int ss,int se,int idx)
{
	if(ss==se)
	{
		stree2[idx]=arr[ss];
		return stree2[idx];
	}

	int mid=(ss+se)/2;

	int x=createsegtree2(stree2,ss,mid,2*idx+1);
	int y=createsegtree2(stree2,mid+1,se,2*idx+2);

	stree2[idx]=min(min(x,y),gcd(x,y));

	return stree2[idx];
}

int rminq(int *stree2,int ss,int se,int q1,int q2,int idx)
{
	if(ss>=q1 && se<=q2)
		return stree2[idx];

	if(q1>se || q2<ss)
		return 1000000000;

	int mid=(ss+se)/2;

	int x=rminq(stree2,ss,mid,q1,q2,2*idx+1);
	int y=rminq(stree2,mid+1,se,q1,q2,2*idx+2);

	return min(min(x,y),gcd(x,y)) ;

}


int main()
{
	int n,q,a,b;
	in(n);   //in(q);
	for(int i=0;i<n;i++)   in(arr[i]);
	int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *stree1 = new int[max_size];
	int *stree2 = new int[max_size];
	memset(stree2,0,sizeof(stree2));
	createsegtree1(stree1,0,n-1,0);
	createsegtree2(stree2,0,n-1,0);

	//for(int i=0;i<10;i++)     cout<<stree2[i]<<"  ";
	//while(q--)
	//{
		//in(a);   in(b);
		a=1,b=n;
		out(rmaxq(stree1,0,n-1,a-1,b-1,0));  printf(" ");
		//out(rminq(stree2,0,n-1,a-1,b-1,0));  printf("\n");
	//}
	return 0;
}
