#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, n, m, r, w, cnt;
    int ans = 0;
    cin >> n >> m >> r;
    vector<int> items(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> items[i];
    while (r--)
    {
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        fill(visited.begin(), visited.end(), false);
        cnt = 0;
        pq.push({0, i});
        while (!pq.empty())
        {
            auto [cur_w, cur_n] = pq.top();
            pq.pop();
            if (cur_w > m)
            {
                while (!pq.empty())
                    pq.pop();
                break;
            }
            if (visited[cur_n])
                continue;
            visited[cur_n] = true;
            cnt += items[cur_n];

            for (auto &[nxt_w, nxt_n] : graph[cur_n])
            {
                pq.push({nxt_w + cur_w, nxt_n});
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}