#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    vector<bool> visited(100001, false);
    int cnt = 0;
    int ans = -1;
    q.push({0, n});
    while (!q.empty())
    {
        auto [cur_w, cur_n] = q.front();
        q.pop();
        visited[cur_n] = true;
        if (ans != -1 && ans < cur_w)
            break;
        if (cur_n == k)
        {
            cnt++;
            ans = cur_w;
            continue;
        }
        int next[3] = {cur_n - 1, cur_n + 1, cur_n * 2};
        for (auto &nxt : next)
        {
            if (nxt < 0 || nxt > 100000)
                continue;
            if (!visited[nxt])
            {
                q.push({cur_w + 1, nxt});
            }
        }
    }

    cout << ans << "\n"
         << cnt;

    return 0;
}