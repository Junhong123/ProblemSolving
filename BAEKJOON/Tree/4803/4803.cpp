#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int cnt;
bool isTree;

void DFS(int root, int prev)
{
    visited[root] = true;
    for (auto next_node : graph[root])
    {
        if (!visited[next_node])
            DFS(next_node, root);
        else if (next_node != prev)
            isTree = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    int cases = 0;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        graph.clear();
        graph.resize(n + 1);
        visited.clear();
        visited.resize(n + 1, false);
        cnt = 0;
        cases++;

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                isTree = true;
                DFS(i, -1);
                if (isTree)
                    cnt++;
            }
        }

        cout << "Case " << cases << ": ";
        if (cnt == 0)
            cout << "No trees.\n";
        else if (cnt == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << cnt << " trees.\n";

        cin >> n >> m;
    }

    return 0;
}