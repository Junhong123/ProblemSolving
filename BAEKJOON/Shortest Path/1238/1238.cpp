#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, n, m, x, w, go_l;
    cin >> n >> m >> x;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> visited(n + 1);
    while (m--)
    {
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push({0, i});
        fill(visited.begin(), visited.end(), false);
        while (!pq.empty())
        {
            auto [cur_w, cur_n] = pq.top();
            pq.pop();
            if (visited[cur_n])
                continue;
            visited[cur_n] = true;
            if (cur_n == x)
            {
                go_l = cur_w;
                break;
            }

            for (auto &[nxt_w, nxt_n] : graph[cur_n])
            {
                pq.push({cur_w + nxt_w, nxt_n});
            }
        }
        while (!pq.empty())
            pq.pop();

        pq.push({0, x});
        fill(visited.begin(), visited.end(), false);
        while (!pq.empty())
        {
            auto [cur_w, cur_n] = pq.top();
            pq.pop();
            if (visited[cur_n])
                continue;
            visited[cur_n] = true;
            if (cur_n == i)
            {
                ans = max(cur_w + go_l, ans);
                break;
            }

            for (auto &[nxt_w, nxt_n] : graph[cur_n])
            {
                pq.push({cur_w + nxt_w, nxt_n});
            }
        }

        while (!pq.empty())
            pq.pop();
    }

    cout << ans;

    return 0;
}