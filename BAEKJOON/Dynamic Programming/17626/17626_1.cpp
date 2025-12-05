#include <bits/stdc++.h>

using namespace std;

vector<int> dp;

int solve(int n)
{
    if (dp[n] != 1e9)
        return dp[n];
    double db = sqrt(n);
    int tmp = floor(db);
    int res = 1e9;
    for (int i = tmp; i > 0; i--)
    {
        res = min(res, solve(n - (i * i)) + 1);
    }
    dp[n] = min(dp[n], res);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    dp.resize(n + 1, 1e9);
    dp[0] = 0;
    dp[1] = 1;
    cout << solve(n);

    return 0;
}