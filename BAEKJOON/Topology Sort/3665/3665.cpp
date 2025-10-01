#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        int first;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, 0);
        vector<int> lastrank1(n + 1);
        vector<int> lastrank2(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            lastrank1[num] = i;
            lastrank2[i] = num;
        }

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                graph[lastrank2[i]].push_back(lastrank2[j]);
                visited[lastrank2[j]]++;
            }
        }

        int m;
        cin >> m;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            if (lastrank1[u] < lastrank1[v])
            {
                graph[u].erase(remove(graph[u].begin(), graph[u].end(), v), graph[u].end());
                graph[v].push_back(u);
                visited[u]++;
                visited[v]--;
            }
            else
            {
                graph[v].erase(remove(graph[v].begin(), graph[v].end(), u), graph[v].end());
                graph[u].push_back(v);
                visited[u]--;
                visited[v]++;
            }
        }

        queue<int> q;
        int idx = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                q.push(i);
        }

        vector<int> ans;
        bool is_ambiguous = false;

        while (!q.empty())
        {
            if (q.size() > 1)
                is_ambiguous = true;
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (auto next : graph[cur])
            {
                if (!--visited[next])
                {
                    q.push(next);
                }
            }
        }

        if (ans.size() != n)
        {
            cout << "IMPOSSIBLE";
        }
        else if (is_ambiguous)
        {
            cout << "?";
        }
        else
        {
            for (auto val : ans)
                cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}