#include <bits/stdc++.h>

using namespace std;

int n, m, b;
vector<vector<int>> arr;

pair<int, int> solve(int goal)
{
    int require = 0;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > goal)
            {
                require -= arr[i][j] - goal;
                time += 2 * (arr[i][j] - goal);
            }
            else if (arr[i][j] < goal)
            {
                require += goal - arr[i][j];
                time += goal - arr[i][j];
            }
        }
    }

    if (require <= b)
        return {time, goal};
    else
        return {1e9, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> b;
    arr.resize(n, vector<int>(m));
    int max_h = -1;
    int min_h = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            max_h = max(max_h, arr[i][j]);
            min_h = min(min_h, arr[i][j]);
        }
    }

    pair<int, int> ans = {1e9, 1e9};

    for (int i = max_h; i >= min_h; i--)
    {
        pair<int, int> tmp = solve(i);
        if (tmp.first < ans.first)
            ans = tmp;
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}