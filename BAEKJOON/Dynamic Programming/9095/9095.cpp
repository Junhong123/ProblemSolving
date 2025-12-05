#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> dp(11);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 10; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    int T, n;

    cin >> T;

    while (T--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}