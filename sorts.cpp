
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
int insertion_sort(int arr[])
{

	int temp,j;
	for(int i=1;i<6;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<arr[j])
				arr[j+1]=arr[j];
			else
				break;
		}
		arr[j+1]=temp;
	}
	for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";
	return 0;
}
void selection_sort(int arr[])
{
	int i,j;
	for(i=0;i<6-1;i++){
		int index=i;
		for(j=i+1;i<6;j++)
		{
			if(arr[index]<=arr[j])
				index=j;
		}
		if(i!=index)
		{
			arr[i]^=arr[index];
			arr[index]^=arr[i];
			arr[i]^=arr[index];
		}
	}
}
void bubble_sort(int arr[])
{
	int i,j;
	for(i=6-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i,6;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int arr[6]={9,8,7,6,5,4};
	insertion_sort(arr);
	selection_sort(arr);
	bubble_sort(arr);
	//getch();
	return 0;
}
/*   fast input output
inline ll input() //for input integers call it long long int n=input();
{
    ll n=0;
    char ch=getchar_unlocked();
    while( ch < '0' || ch > '9' )
    {
        ch=getchar_unlocked();
    }
    while( ch >= '0' && ch <= '9' )
    {
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    }
    return n;
}
inline void output(ll n)     //for output call output(count) and then for space use put('\n');
{
    char b[35];
    ll i=0;
    do
    {
        b[i++]=n%10+48;
        n=n/10;
    }while(n!=0);
    --i;
    while(i>=0)
    putchar_unlocked(b[i--]);
}
inline void faststring(char *str)  //for entering a string use faststring(p);
{
    register char c = 0;
    register long long i = 0;
    while (c < 33)
    c = getchar_unlocked();
    while (c != '\n')
    {
        str[i] = c;
        c = getchar_unlocked();
        ++i;
    }
    str[i] = '\0';
}


*/
