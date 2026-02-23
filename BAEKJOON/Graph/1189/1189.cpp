#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, K;
vector<string> grid;
vector<vector<bool>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs(int r, int c, int dist)
{
    if (r == 0 && c == C - 1)
    {
        return dist == K ? 1 : 0;
    }

    if (dist >= K)
        return 0;

    int path_count = 0;

    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C)
        {
            if (!visited[nr][nc] && grid[nr][nc] != 'T')
            {

                visited[nr][nc] = true;
                path_count += dfs(nr, nc, dist + 1);
                visited[nr][nc] = false;
            }
        }
    }

    return path_count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> R >> C >> K))
        return 0;

    grid.resize(R);
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i)
    {
        cin >> grid[i];
    }

    int start_r = R - 1;
    int start_c = 0;

    visited[start_r][start_c] = true;
    cout << dfs(start_r, start_c, 1) << "\n";

    return 0;
}