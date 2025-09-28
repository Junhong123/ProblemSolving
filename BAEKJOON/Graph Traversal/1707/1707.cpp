#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
set<int> s[2];
int order = 0;
bool isB = true;

void BFS(int r)
{
    queue<int> q;
    q.push(r);
    visited[r] = true;
    s[0].insert(r);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (s[0].find(cur) != s[0].end())
            order = 1;
        else if (s[1].find(cur) != s[1].end())
            order = 0;
        for (auto next : graph[cur])
        {
            if (visited[next])
            {
                int idx = (order + 1) % 2;
                if (s[idx].find(next) != s[idx].end())
                {
                    isB = false;
                    return;
                }
                continue;
            }
            q.push(next);
            visited[next] = true;
            s[order].insert(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, V, E;
    cin >> T;
    while (T--)
    {
        cin >> V >> E;
        graph = vector<vector<int>>(V + 1);
        visited = vector<bool>(V + 1, false);
        s[0].clear();
        s[1].clear();
        isB = true;
        order = 0;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
                BFS(i);
            if (!isB)
                break;
        }

        if (isB)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}