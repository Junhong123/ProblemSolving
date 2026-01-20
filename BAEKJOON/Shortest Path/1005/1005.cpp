#include <bits/stdc++.h>

using namespace std;

int cost[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, T, k, u, v, d, cur, mx;
    bool isP;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        vector<vector<int>> graph(n + 1);
        vector<int> dp(n + 1, 0);
        vector<int> indegree(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            cin >> cost[i];

        for (int i = 0; i < k; ++i)
        {
            cin >> u >> v;
            graph[u].emplace_back(v);
            indegree[v]++;
        }
        cin >> d;
        queue<int> q;
        for (int i = 1; i <= n; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                dp[i] = cost[i];
            }
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (auto &nxt : graph[cur])
            {
                dp[nxt] = max(dp[nxt], dp[cur] + cost[nxt]);
                indegree[nxt]--;
                if (!indegree[nxt])
                    q.push(nxt);
            }
        }

        cout << dp[d] << "\n";
    }

    return 0;
}