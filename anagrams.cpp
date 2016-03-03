#include<cstdio>
#include<iostream>
bool anagram(char a[],char b[]);
int main()
{
    int t;
    char a[50000],b[50000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        if(anagram(a,b))
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
bool anagram(char a[],char b[])
{
int count1[256]={0};
        int count2[256]={0};
        int i;
        for(i=0;a[i]&&b[i];i++)
        {
            count1[a[i]]++;
            count2[b[i]]++;
        }
        if(a[i]||b[i])
            return false;
        for(i=0;i<256;i++)
            if(count1[i]!=count2[i])
                return false;
        return true;
}
