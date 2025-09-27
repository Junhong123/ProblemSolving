#include <bits/stdc++.h>

using namespace std;

vector<int> visited(100001, 0);

void BFS(int n, int k)
{
    visited[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int dx[3] = {cur - 1, cur + 1, cur * 2};
        if (cur == k)
            return;
        for (auto next : dx)
        {
            if (next < 0 || next >= visited.size())
                continue;

            if (visited[next] == 0)
            {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    BFS(n, k);

    cout << visited[k] - 1;
    return 0;
}