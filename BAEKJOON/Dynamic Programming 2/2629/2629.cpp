#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> weight;
bool dp[31][40001];

void solve(int idx, int cur_weight)
{
    if (dp[idx][cur_weight])
        return;

    dp[idx][cur_weight] = true;

    if (idx == n)
        return;

    solve(idx + 1, cur_weight);
    solve(idx + 1, cur_weight + weight[idx]);
    solve(idx + 1, abs(cur_weight - weight[idx]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    weight.resize(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    solve(0, 0);

    int m;
    cin >> m;

    while (m--)
    {
        int num;
        cin >> num;
        if (dp[n][num])
            cout << "Y ";
        else
            cout << "N ";
    }

    cout << "\n";

    return 0;
}