#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v, ans;
    cin >> n;
    int cnt = 0;
    vector<pair<int, int>> arr;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    if (n <= 4)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (graph[i][j] == false)
                {
                    graph[i][j] = true;
                    graph[j][i] = true;
                    arr.emplace_back(i, j);
                    cnt++;
                }
            }
        }
        ans = 1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (graph[1][i] == false)
            {
                graph[1][i] = true;
                graph[i][1] = true;
                arr.emplace_back(1, i);
                cnt++;
            }
        }
        ans = 2;
    }

    cout << cnt << "\n"
         << ans << "\n";

    for (auto &[i, j] : arr)
        cout << i << " " << j << "\n";

    return 0;
}