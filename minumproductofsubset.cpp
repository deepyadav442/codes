#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,j,flag=0;
    scanf("%d",&n);
    int a[100];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0)
            flag=1;
    }
    long int ans=1;
    sort(a,a+n);
    if(flag==0)
        printf("%d\n",a[0]);
    else
    {
            for(i=0;i<n;i++)
            {
                if(a[i]<0&&ans)
                    ans*=a[i];
                else if(a[i]<0&&a[i+1<0]&&ans)
                    ans*=a[i];
                else if(a[i]>0&&a[i<0])
                    ans*=a[i];
            }
            printf("%ld\n",ans);
    }

    return 0;
}
