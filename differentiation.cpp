#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct data
{
	int a,b;
}data;
//void selection(data arr[],ll n)
void bubble(data arr[],ll n)
{
	data temp;
	for(int i=n-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j].b>arr[j+1].b)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	return ;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		data arr[100001];
		for(int i=0;i<n;i++){
			cin>>arr[i].a>>arr[i].b;
		}
		bubble(arr,n);
		for(int i=0;i<n;i++){
			cout<<arr[i].a<<arr[i].b;
		}
		cout<<endl;
	for(int i=n-1;i>=0;i--)
	{
			if(arr[i].b==0);
			else if(arr[i].b==1)
			{
				if(i==0)
				{
					cout<<arr[i].a<<endl;
				}
				else
				{
					cout<<arr[i].a<<"+";
				}
			}
			else if(arr[i].b==2)
			{
				if(i==0)
				{
					cout<<2*arr[i].a<<"x"<<endl;
				}
				else
				{
					cout<<2*arr[i].a<<"x+";
				}
			}
			else
			{
				if(i==0)
				{
					cout<<arr[i].b*arr[i].a<<"x^"<<arr[i].b-1<<endl;
				}
				else
				{
					cout<<arr[i].b*arr[i].a<<"x^"<<arr[i].b-1<<"+";
				}
			}
	}
	}
	return 0;
}
