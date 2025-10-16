#include <bits/stdc++.h>

using namespace std;

vector<int> mem;
vector<int> cost;

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = 0;
    mem.resize(n + 1);
    cost.resize(n + 1);

    for (int i = 0; i < n; i++)
        cin >> mem[i];

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    vector<int> dp(10001, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[i] >= m)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}