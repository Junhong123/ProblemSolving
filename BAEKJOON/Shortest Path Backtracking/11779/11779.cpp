#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> visited(n + 1, INF);
    vector<int> path(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }
    int start_node, destination;
    cin >> start_node >> destination;
    pq.push({0, start_node});
    visited[start_node] = 0;
    while (!pq.empty())
    {
        auto [cur_weight, cur_node] = pq.top();
        pq.pop();
        if (cur_node == destination)
            break;
        for (auto [next_weight, next_node] : graph[cur_node])
        {
            if (visited[next_node] <= cur_weight + next_weight)
                continue;
            visited[next_node] = cur_weight + next_weight;
            pq.push({visited[next_node], next_node});
            path[next_node] = cur_node;
        }
    }

    cout << visited[destination] << "\n";
    int cur = destination;
    vector<int> ans;
    while (cur != 0)
    {
        ans.emplace_back(cur);
        cur = path[cur];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto val : ans)
        cout << val << " ";
    cout << "\n";

    return 0;
}