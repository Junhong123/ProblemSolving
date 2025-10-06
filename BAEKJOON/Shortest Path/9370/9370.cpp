#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 / 3;
vector<vector<pair<int, int>>> graph(2001);
vector<int> visited(2001, INF);
vector<bool> previsit(2001, false);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
        fill(visited.begin(), visited.end(), INF);
        fill(previsit.begin(), previsit.end(), false);
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }
        vector<int> destinations(t);
        for (int i = 0; i < t; i++)
        {
            cin >> destinations[i];
        }
        sort(destinations.begin(), destinations.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        visited[s] = 0;
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
                if ((visited[next_node] == cur_weight + next_weight) && (previsit[next_node]))
                    continue;
                visited[next_node] = cur_weight + next_weight;
                previsit[next_node] = previsit[cur_node];
                if ((cur_node == g && next_node == h) || (cur_node == h && next_node == g))
                {
                    previsit[next_node] = true;
                }
                pq.push({visited[next_node], next_node});
            }
        }
        for (int dest : destinations)
        {
            if (previsit[dest])
                cout << dest << " ";
        }
        cout << "\n";
    }
    return 0;
}