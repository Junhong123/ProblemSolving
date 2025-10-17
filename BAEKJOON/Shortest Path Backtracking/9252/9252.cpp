#include <bits/stdc++.h>

using namespace std;

string str1, str2;
vector<vector<int>> dp;

int LCS(int idx1, int idx2)
{
    if (idx1 >= str1.size() || idx2 >= str2.size())
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];
    if (str1[idx1] == str2[idx2])
    {
        return dp[idx1][idx2] = 1 + LCS(idx1 + 1, idx2 + 1);
    }
    return dp[idx1][idx2] = max(LCS(idx1 + 1, idx2), LCS(idx1, idx2 + 1));
}

int main()
{
    cin >> str1 >> str2;

    dp = vector<vector<int>>(str1.size() + 1, vector<int>(str2.size() + 1, -1));
    int len = LCS(0, 0);
    string res;
    res.resize(len);
    cout << len << "\n";
    int i = 0;
    int j = 0;
    int cnt = 0;

    while (i < str1.size() && j < str2.size())
    {
        if (str1[i] == str2[j])
        {
            res[cnt++] = str1[i];
            i++;
            j++;
        }
        else
        {
            if (dp[i + 1][j] > dp[i][j + 1])
                i++;
            else
                j++;
        }
    }

    cout << res << "\n";

    return 0;
}