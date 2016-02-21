#include<bits/stdc++.h>
using namespace std;
bool find3Numbers(int A[], int arr_size, int sum)
{
   long  int k, r,count=0;
    sort(A,A+arr_size);
    for (int i = 0; i < arr_size - 2; i++)
    {
        for(int j=i+1,k=arr_size-1;j<k;)
        {
            long int curSum=A[i]+A[j]+A[k];
            if(curSum==sum)
            {
                //count+=k-j;
                j++;
                k--;
            }
            else if(curSum<sum)
            {
                j++;
                count++;
            }
            else
                k--;
        }
    }

      return count;
}
int main()
{
    int t,n,sum,A[100001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>A[i];
        cin>>sum;
        cout<<find3Numbers(A, n, sum)+1<<endl;
    }

    return 0;
}
