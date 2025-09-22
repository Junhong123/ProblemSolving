#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll run(vector<ll> &hist, int start, int end)
{
    if (start == end)
    {
        return hist[start];
    }

    int size = hist.size();
    int mid = (start + end) / 2;
    ll l = run(hist, start, mid);
    ll r = run(hist, mid + 1, end);

    int left = mid;
    int right = mid + 1;
    ll h = min(hist[left], hist[right]);

    ll maxArea = max({l, r, h * 2});

    while (left > start || right < end)
    {
        if (right != end && (left == start || hist[right + 1] >= hist[left - 1]))
        {
            right++;
            h = min(h, hist[right]);
        }
        else
        {
            left--;
            h = min(h, hist[left]);
        }
        maxArea = max(maxArea, h * (right - left + 1));
    }

    return maxArea;
}

int main()
{
    int n;

    while (true)
    {
        cin >> n;

        if (n == 0)
            break;

        vector<ll> hist(n);
        for (int i = 0; i < n; i++)
        {
            cin >> hist[i];
        }

        cout << run(hist, 0, n - 1) << "\n";
    }
    return 0;
}