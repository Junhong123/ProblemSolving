#include <bits/stdc++.h>

using namespace std;

vector<int> value;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    value.resize(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];

    vector<int> dp(k + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = value[i]; j <= k; j++)
        {
            dp[j] += dp[j - value[i]];
        }
    }

    cout << dp[k] << "\n";

    return 0;
}