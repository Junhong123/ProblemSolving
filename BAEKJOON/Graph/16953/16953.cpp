#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    queue<pair<long long, int>> q;
    cin >> n >> m;
    int ans;
    bool isC = false;
    q.push({n, 1});
    while (!q.empty())
    {
        auto [cur, cnt] = q.front();
        q.pop();
        if (cur == m)
        {
            ans = cnt;
            isC = true;
            break;
        }
        if (cur * 2 <= m)
            q.push({cur * 2, cnt + 1});
        if (cur * 10 + 1 <= m)
            q.push({cur * 10 + 1, cnt + 1});
    }

    if (isC)
        cout << ans;
    else
        cout << "-1";
    return 0;
}