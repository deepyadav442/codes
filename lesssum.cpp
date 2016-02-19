#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
    sort(arr, arr+n);

    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;

        while (j < k)
        {

            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;

        else
            {
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum,arr[10001];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>sum;
        cout << countTriplets(arr, n, sum) << endl;

    }
    return 0;
}
