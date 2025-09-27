#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;
int order = 1;
vector<int> ans;

void DFS(int r, int c)
{
    visited[r][c] = order++;
    if (r - 1 >= 0 && graph[r - 1][c] != 0 && visited[r - 1][c] == 0)
    {
        DFS(r - 1, c);
    }
    if (r + 1 < graph.size() && graph[r + 1][c] != 0 && visited[r + 1][c] == 0)
    {
        DFS(r + 1, c);
    }
    if (c - 1 >= 0 && graph[r][c - 1] != 0 && visited[r][c - 1] == 0)
    {
        DFS(r, c - 1);
    }
    if (c + 1 < graph.size() && graph[r][c + 1] != 0 && visited[r][c + 1] == 0)
    {
        DFS(r, c + 1);
    }
}

int main()
{
    int n;
    cin >> n;

    graph.resize(n, vector<int>(n));
    visited.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = (int)str[j] - 48;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0 && visited[i][j] == 0)
            {
                DFS(i, j);
                ans.push_back(order - 1);
                order = 1;
            }
        }
    }

    cout << ans.size() << "\n";

    sort(ans.begin(), ans.end());

    for (auto val : ans)
        cout << val << "\n";

    return 0;
}