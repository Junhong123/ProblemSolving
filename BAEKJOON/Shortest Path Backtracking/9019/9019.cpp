#include <bits/stdc++.h>

using namespace std;

vector<int> dp(10000, -1);
vector<pair<char, int>> path(10000);
queue<int> q;

void check(int cur, int next, char DSLR)
{
    if (dp[next] == -1)
    {
        dp[next] = dp[cur] + 1;
        q.push(next);
        path[next] = {DSLR, cur};
    }

    return;
}

void solve(int cur)
{
    int next = (cur * 2) % 10000;
    check(cur, next, 'D');

    next = cur - 1;
    if (cur == 0)
        next = 9999;
    check(cur, next, 'S');

    int d1 = cur / 1000;
    int d2 = (cur - d1 * 1000) / 100;
    int d3 = ((cur - d1 * 1000) - d2 * 100) / 10;
    int d4 = cur % 10;

    next = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
    check(cur, next, 'L');

    next = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
    check(cur, next, 'R');

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        fill(dp.begin(), dp.end(), -1);
        path.clear();
        path.resize(10000);
        q.push(n1);
        path[n1].second = -1;
        dp[n1] = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == n2)
            {
                break;
            }
            solve(cur);
        }

        while (!q.empty())
            q.pop();

        int cur = n2;
        vector<char> ans;
        while (cur != n1)
        {
            ans.emplace_back(path[cur].first);
            cur = path[cur].second;
        }

        reverse(ans.begin(), ans.end());

        for (auto res : ans)
        {
            cout << res;
        }
        cout << "\n";
    }

    return 0;
}