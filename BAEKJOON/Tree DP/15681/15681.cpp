#include <bits/stdc++.h>

using namespace std;

vector<int> depth;
vector<int> sub_size;
vector<vector<int>> graph;

void set_depth(int n, int d)
{
    depth[n] = d;
    for (auto &next : graph[n])
    {
        if (depth[next] == -1)
            set_depth(next, d + 1);
    }
}

void set_size(int n)
{
    if (sub_size[n] != 0)
        return;
    if (graph[n].size() == 1 && depth[n] != 0)
    {
        sub_size[n] = 1;
        return;
    }

    for (auto &next : graph[n])
    {
        if (depth[next] > depth[n])
        {
            set_size(next);
            sub_size[n] += sub_size[next];
        }
    }

    sub_size[n]++;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, num;
    cin >> n >> r >> q;

    graph.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    depth.resize(n + 1, -1);
    set_depth(r, 0);

    sub_size.resize(n + 1, 0);
    set_size(r);

    while (q--)
    {
        cin >> num;
        cout << sub_size[num] << "\n";
    }

    return 0;
}