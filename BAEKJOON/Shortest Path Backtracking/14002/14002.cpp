#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n, 0);
    vector<int> path(n);
    int max_len = 1;
    int start = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j] && dp[i] < 1 + dp[j])
            {
                dp[i] = 1 + dp[j];
                path[i] = j;
            }
        }
        if (max_len < dp[i])
        {
            max_len = dp[i];
            start = i;
        }
    }

    cout << max_len << "\n";
    int cur = start;
    for (int i = 0; i < max_len; i++)
    {
        cout << arr[cur] << " ";
        cur = path[cur];
    }
    cout << "\n";

    return 0;
}