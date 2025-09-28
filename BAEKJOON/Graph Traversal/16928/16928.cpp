#include <bits/stdc++.h>

using namespace std;

vector<int> graph(101, 0);
vector<int> visited(101, -1);

void BFS()
{
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == 100)
            return;
        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            if (next > 100 || visited[next] != -1)
                continue;
            while (graph[next] != 0)
            {
                next = graph[next];
            }
            if (visited[next] == -1)
            {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n + m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u] = v;
    }

    BFS();

    cout << visited[100] << "\n";

    return 0;
}