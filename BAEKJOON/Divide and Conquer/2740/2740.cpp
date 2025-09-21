#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> v1(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v1[i][j];
        }
    }

    cin >> m >> k;
    vector<vector<int>> v2(m, vector<int>(k));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> v2[i][j];
        }
    }

    vector<vector<int>> res(n, vector<int>(k, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int r = 0; r < m; r++)
            {
                res[i][j] += v1[i][r] * v2[r][j];
            }
        }
    }

    for (auto arr : res)
    {
        for (auto val : arr)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}