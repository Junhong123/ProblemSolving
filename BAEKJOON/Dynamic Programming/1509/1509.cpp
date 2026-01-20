#include <bits/stdc++.h>

using namespace std;

bool isPal[2501][2501];
int dp[2501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    const int n = str.length();

    for (int i = 0; i < n; ++i)
        isPal[i][i] = true;

    for (int i = 0; i < n - 1; ++i)
        if (str[i] == str[i + 1])
            isPal[i][i + 1] = true;

    for (int k = 2; k < n; ++k)
    {
        for (int i = 0; i < n - k; ++i)
        {
            if (isPal[i + 1][i + k - 1] && str[i] == str[i + k])
                isPal[i][i + k] = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (isPal[0][i])
            dp[i] = 1;
        else
        {
            dp[i] = i + 1;

            for (int j = 0; j < i; ++j)
            {
                if (isPal[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[n - 1];

    return 0;
}