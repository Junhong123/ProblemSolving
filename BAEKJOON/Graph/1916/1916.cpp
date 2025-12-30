#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, w, start, end, ans;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }
    cin >> start >> end;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        auto [cur_w, cur_n] = pq.top();
        pq.pop();
        if (dist[cur_n] < cur_w)
            continue;
        if (cur_n == end)
        {
            ans = cur_w;
            break;
        }
        for (auto &[next_w, next_n] : graph[cur_n])
        {
            if (dist[next_n] > cur_w + next_w)
            {
                dist[next_n] = cur_w + next_w;
                pq.push({cur_w + next_w, next_n});
            }
        }
    }

    cout << ans;

    return 0;
}