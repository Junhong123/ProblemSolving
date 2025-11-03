#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<tuple<int, int, int>> bridges;
int cnt = 1;
int n, m;

void find_bridge(int y, int x)
{
    visited[y][x] = true;
    int dist = 1;
    for (int i = y - 1; i >= 0; i--)
    {
        if (arr[i][x] != 0)
        {
            if (dist >= 3)
            {
                bridges.emplace_back(dist, arr[y][x], arr[i][x]);
            }
            break;
        }
        dist++;
    }

    dist = 1;
    for (int i = y + 1; i < n; i++)
    {
        if (arr[i][x] != 0)
        {
            if (dist >= 3)
            {
                bridges.emplace_back(dist, arr[y][x], arr[i][x]);
            }
            break;
        }
        dist++;
    }

    dist = 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (arr[y][i] != 0)
        {
            if (dist >= 3)
            {
                bridges.emplace_back(dist, arr[y][x], arr[y][i]);
            }
            break;
        }
        dist++;
    }

    dist = 1;
    for (int i = x + 1; i < m; i++)
    {
        if (arr[y][i] != 0)
        {
            if (dist >= 3)
            {
                bridges.emplace_back(dist, arr[y][x], arr[y][i]);
            }
            break;
        }
        dist++;
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (arr[ny][nx] != 0 && visited[ny][nx] == false)
        {
            find_bridge(ny, nx);
        }
    }
}

void set_num(int y, int x)
{
    arr[y][x] = cnt;
    visited[y][x] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (arr[ny][nx] != 0 && visited[ny][nx] == false)
        {
            set_num(ny, nx);
        }
    }
}

struct UF
{
    vector<int> parent, rank;
    UF(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
        return true;
    }

    bool isPossible()
    {
        for (int i = 1; i < parent.size(); i++)
        {
            for (int j = i + 1; j < parent.size(); j++)
            {
                if (unite(i, j))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    vector<pair<int, int>> yx;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0 && visited[i][j] == false)
            {
                set_num(i, j);
                yx.emplace_back(i, j);
                cnt++;
            }
        }
    }

    fill(visited.begin(), visited.end(), vector<bool>(m, false));

    for (auto &[i, j] : yx)
    {
        find_bridge(i, j);
    }
    sort(bridges.begin(), bridges.end());

    UF uf(cnt - 1);
    int ans = 0;
    for (auto &[w, idx1, idx2] : bridges)
    {
        if (uf.unite(idx1, idx2))
            ans += w - 1;
    }

    if (uf.isPossible())
        cout << ans << "\n";
    else
        cout << "-1\n";

    return 0;
}