#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,arr[10001];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int pagecount=1,count=0,previous=1;
    for(int i=0;i<n;i++)
    {
        //if(pagecount<=arr[i]){
          //      cout<<pagecount<<"hello";
          //  count++;
        ////}
        previous=pagecount;
        if(arr[i]%k==0)
            pagecount+=arr[i]/k;
        else
            pagecount+=arr[i]/k+1;
        int z=1;
        for(int j=previous;j<=pagecount;j++)
        {
            int x=k;
            while(x--)
            {
                if(z>arr[i])
                    break;
                if(j==z)
                    count++;
                z++;
            }
        }
        //int ans=pagecount-previous;
        //cout<<previous;
        //cout<<pagecount<<endl;

    }
    cout<<count;
    return 0;
}
