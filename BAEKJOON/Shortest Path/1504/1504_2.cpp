#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 / 3;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n + 1);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int v1, v2;
    cin >> v1 >> v2;
    int ans[3][2];
    int start[3] = {1, v1, v2};
    for (int i = 0; i < 3; i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n + 1, INF);
        pq.push({0, start[i]});
        visited[start[i]] = 0;
        while (!pq.empty())
        {
            auto [cur_weight, cur_node] = pq.top();
            pq.pop();
            if (visited[cur_node] < cur_weight)
                continue;
            for (auto [next_weight, next_node] : graph[cur_node])
            {
                if (visited[next_node] < cur_weight + next_weight)
                    continue;
                visited[next_node] = cur_weight + next_weight;
                pq.push({visited[next_node], next_node});
            }
        }

        if (i == 0)
        {
            ans[i][0] = visited[v1];
            ans[i][1] = visited[v2];
        }
        else if (i == 1)
        {
            ans[i][0] = visited[v2];
            ans[i][1] = visited[n];
        }
        else
        {
            ans[i][0] = visited[v1];
            ans[i][1] = visited[n];
        }
    }

    long long path1 = ans[0][0] + ans[1][0] + ans[2][1];
    long long path2 = ans[0][1] + ans[2][0] + ans[1][1];

    long long res = min(path1, path2);

    if (res >= INF)
        cout << "-1\n";
    else
        cout << res << "\n";

    return 0;
}