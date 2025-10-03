#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int checkV(int v1, int v2)
{
    int v;
    if (v1 == 0 && v2 == 0)
        v = 0;
    else if (v1 == 1 && v2 == 0)
        v = 1;
    else if (v1 == 0 && v2 == 1)
        v = 2;
    else
        v = 3;
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<int>> visited(n + 1, vector<int>(4, INF));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int v1, v2;
    cin >> v1 >> v2;

    if (v1 == 1)
        pq.push({0, 1, 1, 0});
    else
        pq.push({0, 1, 0, 0});

    while (!pq.empty())
    {
        auto [cur_weight, cur_node, cur_v1, cur_v2] = pq.top();
        pq.pop();
        int v = checkV(cur_v1, cur_v2);
        if (visited[cur_node][v] < cur_weight)
            continue;
        for (auto next : graph[cur_node])
        {
            int nv1, nv2;
            if (next.second == v1)
            {
                nv1 = 1;
                nv2 = cur_v2;
            }
            else if (next.second == v2)
            {
                nv1 = cur_v1;
                nv2 = 1;
            }
            else
            {
                nv1 = cur_v1;
                nv2 = cur_v2;
            }
            int nv = checkV(nv1, nv2);
            if (visited[next.second][nv] < cur_weight + next.first)
                continue;
            visited[next.second][nv] = cur_weight + next.first;
            pq.push({visited[next.second][nv], next.second, nv1, nv2});
        }
    }

    if (visited[n][3] == INF)
        cout << "-1\n";
    else
        cout << visited[n][3] << "\n";

    return 0;
}