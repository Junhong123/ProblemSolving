#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<vector<int>> dp;

int solve(int left, int right)
{
    if (left > right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];

    int score1 = arr[left] + min(solve(left + 2, right), solve(left + 1, right - 1));
    int score2 = arr[right] + min(solve(left, right - 2), solve(left + 1, right - 1));
    dp[left][right] = max(score1, score2);
    return dp[left][right];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        arr = vector<int>(n);
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(0, n - 1) << "\n";
    }
    return 0;
}