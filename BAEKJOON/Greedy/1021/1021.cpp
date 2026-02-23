#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; ++i)
        dq.push_back(i);
    int ans = 0;
    while (m--)
    {
        int num, idx;
        cin >> num;
        for (int i = 0; i < dq.size(); ++i)
            if (dq[i] == num)
                idx = i;
        int l_dist = idx;
        int r_dist = dq.size() - idx;

        if (l_dist <= r_dist)
        {
            while (l_dist--)
            {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                ans++;
            }
        }
        else
        {
            while (r_dist--)
            {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                ans++;
            }
        }
        dq.pop_front();
    }

    cout << ans;

    return 0;
}