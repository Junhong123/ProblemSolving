#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        for (int j = 0; j < m; ++j)
            arr[i][j] = str[j];
    }

    int ans = 1;
    if (n == 1 || m == 1)
    {
        cout << 1;
        return 0;
    }

    vector<int> rgt;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            int cur = arr[i][j];
            rgt.clear();
            for (int k = j + 1; k < m; ++k)
            {
                if (arr[i][k] == cur)
                    rgt.emplace_back(k);
            }
            if (!rgt.empty())
            {
                for (auto &nxt : rgt)
                {
                    int dst = nxt - j;
                    if (i + dst < n)
                        if (arr[i + dst][j] == cur && arr[i + dst][nxt] == cur)
                            ans = max(ans, (dst + 1) * (dst + 1));
                }
            }
        }
    }

    cout << ans;

    return 0;
}