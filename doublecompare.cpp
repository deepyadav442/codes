#include<bits/stdc++.h>
using namespace std;
#define eps 0.000001
typedef long long ll;
bool comp(double a, double b)
{
    //double c=a-b;
   // printf("%lf  ",c);
    return (a-b)>((fabs(a)<fabs(b)?fabs(b):fabs(a))*eps);
}
int main()
{
    ll i,t,n,q;
    float arr[100001];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        for(i=0;i<n;i++)
            scanf("%f",&arr[i]);
        float x;
       // bucketSort(arr,n);
       // for(i=0;i<n;i++)
         //   printf("%f ",arr[i]);
        for(i=0;i<q;i++)
        {
            scanf("%f",&x);
            ll count=0;
            for(int j=0;j<n;j++)
            {
                //double c=arr[j]-x;
                //if(c>=eps)
                  //  count++;
                //if(comp(arr[j],x)==1)
                  //  count++;
                  if(arr[j]>(x+eps))
                    count++;
            }
            printf("%lld\n",count);
        }
    }
    return 0;
}
