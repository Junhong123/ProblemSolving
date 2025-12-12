#include <bits/stdc++.h>

using namespace std;

int N, r, c;
int cnt = 0;
int ans = -1;

void solve(int sx, int ex, int sy, int ey)
{
    if (ans != -1)
        return;
    int size = (ex - sx + 1) * (ey - sy + 1);
    if (size > 4)
    {
        int half_x = (sx + ex) / 2;
        int half_y = (sy + ey) / 2;
        solve(sx, half_x, sy, half_y);
        solve(half_x + 1, ex, sy, half_y);
        solve(sx, half_x, half_y + 1, ey);
        solve(half_x + 1, ex, half_y + 1, ey);
    }
    else
    {
        if (sx == c && sy == r)
            ans = cnt;
        else if (ex == c && sy == r)
            ans = cnt + 1;
        else if (sx == c && ey == r)
            ans = cnt + 2;
        else if (ex == c && ey == r)
            ans = cnt + 3;
        else
            cnt += 4;
    }
}

int main()
{
    cin >> N >> r >> c;
    solve(0, pow(2, N) - 1, 0, pow(2, N) - 1);
    cout << ans;
    return 0;
}