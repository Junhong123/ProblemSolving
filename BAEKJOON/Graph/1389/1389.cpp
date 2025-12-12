#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1);
    int min_kevin = 1e9;
    int ans = -1;
    while (m--)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        fill(visited.begin(), visited.end(), false);
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;
        while (!q.empty())
        {
            auto [cur, dist] = q.front();
            q.pop();
            cnt += dist;
            for (auto &next : graph[cur])
                if (!visited[next])
                {
                    q.push({next, dist + 1});
                    visited[next] = true;
                }
        }

        if (min_kevin > cnt)
        {
            min_kevin = cnt;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}