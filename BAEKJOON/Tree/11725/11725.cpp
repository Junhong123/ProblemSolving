#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> depth(n + 1, 0);
    depth[1] = 1;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    queue<int> q;
    q.push(1);
    int cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (auto next : tree[cur])
        {
            if (depth[next] != 0)
                continue;
            depth[next] = depth[cur] + 1;
            q.push(next);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int ans = 0;
        int dep = depth[i];
        for (auto adj : tree[i])
        {
            if (depth[adj] < dep)
            {
                dep = depth[adj];
                ans = adj;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}