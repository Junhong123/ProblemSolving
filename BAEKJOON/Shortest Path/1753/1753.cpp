#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k;
    cin >> v >> e >> k;

    vector<int> dist(v + 1, INF);
    dist[k] = 0;
    vector<vector<pair<int, int>>> graph(v + 1);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    while (!pq.empty())
    {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();
        if (dist[cur_node] < cur_weight)
            continue;
        for (auto next : graph[cur_node])
        {
            if (dist[next.first] < cur_weight + next.second)
                continue;
            dist[next.first] = cur_weight + next.second;
            pq.push({dist[next.first], next.first});
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}