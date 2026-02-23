#include <bits/stdc++.h>

using namespace std;

bool chk(int x, int y, int cx, int cy, int r)
{
    int dist = (y - cy) * (y - cy) + (x - cx) * (x - cx);
    if (dist < r * r)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int x1, y1, x2, y2, n, cx, cy, r;
        int ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        while (n--)
        {
            cin >> cx >> cy >> r;
            bool chk1 = chk(x1, y1, cx, cy, r);
            bool chk2 = chk(x2, y2, cx, cy, r);
            if (chk1 ^ chk2)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}