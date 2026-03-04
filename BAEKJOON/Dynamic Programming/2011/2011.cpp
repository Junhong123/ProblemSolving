#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    if (str[0] == '0')
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> dp(str.size(), 0);
    dp[0] = 1;

    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] != '0')
            dp[i] += dp[i - 1];

        if (str[i - 1] == '1' || (str[i - 1] == '2' && (str[i] >= '0' && str[i] <= '6')))
        {
            if (i == 1)
                dp[i]++;
            else
                dp[i] += dp[i - 2];
        }

        dp[i] %= 1000000;
    }

    cout << dp[str.size() - 1] << "\n";

    return 0;
}