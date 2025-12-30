#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c;
    cin >> n;
    int max_dp[3], min_dp[3];
    int prev_max[3], prev_min[3];
    cin >> a >> b >> c;
    max_dp[0] = min_dp[0] = a;
    max_dp[1] = min_dp[1] = b;
    max_dp[2] = min_dp[2] = c;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            prev_max[j] = max_dp[j];
            prev_min[j] = min_dp[j];
        }

        cin >> a >> b >> c;
        max_dp[0] = max(prev_max[0], prev_max[1]) + a;
        max_dp[1] = max({prev_max[0], prev_max[1], prev_max[2]}) + b;
        max_dp[2] = max(prev_max[1], prev_max[2]) + c;

        min_dp[0] = min(prev_min[0], prev_min[1]) + a;
        min_dp[1] = min({prev_min[0], prev_min[1], prev_min[2]}) + b;
        min_dp[2] = min(prev_min[1], prev_min[2]) + c;
    }

    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << " " << min({min_dp[0], min_dp[1], min_dp[2]});
    return 0;
}