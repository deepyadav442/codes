// check whether string can be divided into two exactly same parts by removing atmost 1 character..
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000001];
int main()
{
    ll d;
    scanf("%lld",&d);
    while(d--)
    {
        scanf("%s",s);
        ll i,j,flag=0;
        ll length=strlen(s);
        if(length==1)
        {
            printf("NO\n");
            continue;
        }
        //cout<<length<<endl;
        if(length%2==0)
        {
            for(i=0,j=length/2;i<length/2&&j<length;i++,j++)
            {
                if(s[i]!=s[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                printf("NO\n");
            else
                printf("YES\n");
            //cout<<"even"<<endl;
        }
        else
        {
           // cout<<"odd"<<endl;
            int flag2=0,flag=0;
            for(i=0,j=length/2;i<length/2&&j<length;)
            {
                if((s[i]==s[j]))
                {
                    i++;
                    j++;
                }
                else if((s[i]!=s[j])&&(flag2==0))
                {
                    j++;
                    flag2=1;
                }
                else
                {
                    //cout<<"hello";
                    flag=1;
                    break;
                }
            }
            //cout<<i<<j;
            int deep=0;
            flag2=0;
            for(i=0,j=length/2+1;i<=length/2&&j<length;)
            {
                if((s[i]==s[j]))
                {
                    i++;
                    j++;
                }
                else if((s[i]!=s[j])&&(flag2==0))
                {
                    i++;
                    flag2=1;
                }
                else
                {
                    deep=1;
                    break;

                }
            }
            if(flag==0||deep==0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
