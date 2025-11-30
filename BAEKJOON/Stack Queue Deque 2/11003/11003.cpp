#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, cur;
    cin >> n >> l;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        while (!dq.empty() && dq.back().first > cur)
            dq.pop_back();
        dq.push_back({cur, i});
        if (dq.front().second <= i - l)
            dq.pop_front();

        cout << dq.front().first << " ";
    }

    return 0;
}