#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int dx[3] = {0, 1, 2};
    int dy[3] = {0, 1, 2};
    cin >> n >> m;
    vector<string> arr(n);
    vector<string> ans(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i)
        cin >> ans[i];

    int cnt = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            if (arr[i][j] != ans[i][j])
            {
                cnt++;
                for (int k = 0; k < 9; ++k)
                {
                    if (arr[i + dy[k / 3]][j + dx[k % 3]] == '1')
                        arr[i + dy[k / 3]][j + dx[k % 3]] = '0';
                    else
                        arr[i + dy[k / 3]][j + dx[k % 3]] = '1';
                }
            }
        }
    }

    if (arr == ans)
        cout << cnt;
    else
        cout << -1;

    return 0;
}