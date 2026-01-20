#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int dp[100001][5][5];

int calc_cost(int cur, int nxt)
{
    if (cur == 0)
        return 2;
    else
    {
        if (cur == nxt)
            return 1;
        else if (abs(cur - nxt) == 2)
            return 4;
        else
            return 3;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> arr;
    while (true)
    {
        cin >> n;
        if (n)
            arr.emplace_back(n);
        else
            break;
    }

    int size = arr.size();

    memset(dp, 0x3f, sizeof(dp));

    dp[0][0][0] = 0;

    for (int i = 0; i < size; ++i)
    {
        for (int l = 0; l < 5; ++l)
        {
            for (int r = 0; r < 5; ++r)
            {
                int cur_cost = dp[i][l][r];
                if (cur_cost == INF)
                    continue;
                if (r != arr[i])
                {
                    int nxt_cost = cur_cost + calc_cost(l, arr[i]);
                    dp[i + 1][arr[i]][r] = min(dp[i + 1][arr[i]][r], nxt_cost);
                }

                if (l != arr[i])
                {
                    int nxt_cost = cur_cost + calc_cost(r, arr[i]);
                    dp[i + 1][l][arr[i]] = min(dp[i + 1][l][arr[i]], nxt_cost);
                }
            }
        }
    }

    int ans = INF;
    for (int l = 0; l < 5; ++l)
        for (int r = 0; r < 5; ++r)
            ans = min(ans, dp[size][l][r]);

    cout << ans;

    return 0;
}