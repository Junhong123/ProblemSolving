#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prev, cur, n, m, k;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> ans;
    while (m--)
    {
        cin >> k;
        prev = -1;
        while (k--)
        {
            cin >> cur;
            if (prev != -1)
            {
                graph[prev].emplace_back(cur);
                indegree[cur]++;
            }
            prev = cur;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!indegree[i])
            q.push(i);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        ans.emplace_back(cur);
        for (auto &nxt : graph[cur])
        {
            indegree[nxt]--;
            if (!indegree[nxt])
                q.push(nxt);
        }
    }

    if (ans.size() == n)
    {
        for (auto &v : ans)
            cout << v << "\n";
    }
    else
        cout << "0\n";

    return 0;
}