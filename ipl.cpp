#include <iostream>

using namespace std;

int cost[1000006];
int n;
int ans[1000006];

int main()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> cost[i];
        }
        ans[n - 1] = cost[n - 1];
        ans[n - 2] = cost[n - 2];
        for(int i = n - 3; i > 0; i--)
        {
                ans[i] = cost[i] + min(ans[i + 1], ans[i + 2]);
        }

        int curBest = cost[n] + min(ans[1], ans[2]);

        ans[n] = cost[n];
        ans[n - 1] = cost[n - 1];
        for(int i = n - 2; i > 0; i--)
        {
                ans[i] = cost[i] + min(ans[i + 1], ans[i + 2]);
        }

        curBest = min(curBest, ans[1]);

        cout << curBest;
}
