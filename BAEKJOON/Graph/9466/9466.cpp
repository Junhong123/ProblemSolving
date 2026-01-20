#include <bits/stdc++.h>

using namespace std;

int graph[100001];
int start, cnt;
bool isC;
bool finished[100001];
bool visited[100001];

void DFS(int cur)
{
    visited[cur] = true;
    if (!visited[graph[cur]])
        DFS(graph[cur]);
    else
    {
        if (!finished[graph[cur]])
        {
            for (int nxt = graph[cur]; nxt != cur; nxt = graph[nxt])
                cnt++;
            cnt++;
        }
    }

    finished[cur] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, num;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> graph[i];
        cnt = 0;
        fill(visited, visited + n + 1, false);
        fill(finished, finished + n + 1, false);
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
                DFS(i);
        }

        cout << n - cnt << "\n";
    }

    return 0;
}