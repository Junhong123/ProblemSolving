#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> dp(100001, -1);
    queue<int> q;
    vector<int> path(100001);
    q.push(n);
    dp[n] = 0;
    bool end = false;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        int dx[3] = {-1, 1, cur};
        for (int i = 0; i < 3; i++)
        {
            int nidx = cur + dx[i];
            if (nidx > max(n, k) * 2 || nidx > 100000 || nidx < 0 || dp[nidx] != -1)
                continue;
            q.push(nidx);
            dp[nidx] = dp[cur] + 1;
            path[nidx] = cur;
            if (nidx == k)
                end = true;
        }
        if (end)
            break;
    }

    vector<int> arr;
    int current = path[k];
    for (int i = 0; i < dp[k]; i++)
    {
        arr.push_back(current);
        current = path[current];
    }
    cout << dp[k] << "\n";
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << k << "\n";

    return 0;
}