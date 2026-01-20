#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1001][1001];
int whatgroup[1001][1001];
bool visited[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<int> groupSize;

void bfs(int y, int x, int group)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    whatgroup[y][x] = group;
    while (!q.empty())
    {
        auto [cur_y, cur_x] = q.front();
        q.pop();
        groupSize[group]++;
        for (int i = 0; i < 4; ++i)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                if (arr[ny][nx] == 0 && whatgroup[ny][nx] == 0)
                {
                    q.push({ny, nx});
                    whatgroup[ny][nx] = group;
                }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int groupCount = 1;
    groupSize.push_back(0);
    vector<pair<int, int>> walls;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = str[j] - '0';
            if (arr[i][j] == 1)
                walls.emplace_back(i, j);
        }
    }

    memset(whatgroup, 0, sizeof(whatgroup));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 0 && whatgroup[i][j] == 0)
            {
                groupSize.push_back(0);
                bfs(i, j, groupCount);
                groupCount++;
            }
        }
    }

    for (auto &[cur_y, cur_x] : walls)
    {
        set<int> s;
        int tot = 0;
        for (int i = 0; i < 4; ++i)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                if (arr[ny][nx] == 0)
                {
                    s.insert(whatgroup[ny][nx]);
                }
        }
        for (auto &gr : s)
            tot += groupSize[gr];
        arr[cur_y][cur_x] = (tot + 1) % 10;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << arr[i][j];
        cout << "\n";
    }

    return 0;
}