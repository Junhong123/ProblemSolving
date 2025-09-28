#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> visited;

void BFS(int x1, int y1, int x2, int y2)
{
    visited[x1][y1] = 1;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        pair<int, int> next[8] = {{cur.first + 2, cur.second + 1}, {cur.first + 1, cur.second + 2}, {cur.first + 2, cur.second - 1}, {cur.first + 1, cur.second - 2}, {cur.first - 2, cur.second + 1}, {cur.first - 1, cur.second + 2}, {cur.first - 2, cur.second - 1}, {cur.first - 1, cur.second - 2}};
        for (auto next : next)
        {
            if (next.first < 0 || next.first >= visited.size() || next.second < 0 || next.second >= visited.size())
                continue;
            if (visited[next.first][next.second] == 0)
            {
                q.push(next);
                visited[next.first][next.second] = visited[cur.first][cur.second] + 1;
                if (next == pair{x2, y2})
                {
                    return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int l;
        cin >> l;
        visited = vector<vector<int>>(l, vector<int>(l, 0));
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2)
        {
            cout << "0\n";
            continue;
        }
        BFS(x1, y1, x2, y2);
        cout << visited[x2][y2] - 1 << "\n";
    }
    return 0;
}