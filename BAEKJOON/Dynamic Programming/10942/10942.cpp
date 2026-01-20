#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool isp;
    int l, start, end, n, m;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        dp[i][i] = true;
    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = true;
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            if (arr[i] == arr[i + len - 1] && dp[i + 1][i + len - 2])
                dp[i][i + len - 1] = true;
        }
    }

    cin >> m;
    while (m--)
    {
        cin >> start >> end;
        if (dp[start][end])
            cout << "1";
        else
            cout << "0";
        cout << "\n";
    }
    return 0;
}