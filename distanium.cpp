#include<bits/stdc++.h>
using namespace std;
int main()
{
    typedef long int ll;
    ll n,q,arr[100001],i;
    scanf("%ld%ld",&n,&q);
    for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
    sort(arr,arr+n);
    while(q--)
    {
        ll a,l,r,count=1,x,y,j;
        scanf("%ld",&a);
        if(a==5)
        {
            scanf("%ld%ld",&l,&r);
            for(i=l-1;i<r-1;i++)
            {
                if(arr[i]==arr[i+1])
                    continue;
                else
                    count++;
            }
            printf("%ld\n",count);
        }
        else if(a==3)
            scanf("%ld",&x);
        else if(a==2)
        {
            scanf("%ld%ld",&x,&y);
            //a[x-1]=y;
        }
        else if(a==1){
            scanf("%ld%ld",&x,&y);
            for(i=x-1;i<y-1;i++)
            {
                if(arr[i]==arr[i+1])
                    continue;
                else
                {
                    for(j=i+1;j<y-1;j++)
                    {
                        if(arr[j]==arr[j+1])
                            continue;
                        else
                            count+=(arr[i]*arr[j]*arr[j+1]);
                    }
                }
            }
            printf("%ld\n",count);
        }
        else
            scanf("%ld%ld",&x,&y);
    }
    return 0;
}
