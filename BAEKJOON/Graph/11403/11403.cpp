#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (num == 1)
            {
                graph[i].emplace_back(j);
            }
        }

    queue<int> q;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        fill(visited.begin(), visited.end(), false);
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto &next : graph[cur])
            {
                if (!visited[next])
                {
                    arr[i][next] = 1;
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }

    for (auto &row : arr)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}