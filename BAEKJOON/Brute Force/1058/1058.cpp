#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int n;
    cin >> n;
    vector<vector<bool>> arr(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        for (int j = 0; j < n; ++j)
            if (str[j] == 'Y')
                arr[i][j + 1] = true;
    }

    vector<int> cnt(n + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        vector<bool> is_2f(n + 1, false);
        for (int j = 1; j <= n; ++j)
        {
            if (arr[i][j])
            {
                if (!is_2f[j])
                {
                    cnt[i]++;
                    is_2f[j] = true;
                }
                for (int k = 1; k <= n; ++k)
                {
                    if (arr[j][k] && !is_2f[k] && i != k)
                    {
                        cnt[i]++;
                        is_2f[k] = true;
                    }
                }
            }
        }
        ans = max(ans, cnt[i]);
    }

    cout << ans;

    return 0;
}