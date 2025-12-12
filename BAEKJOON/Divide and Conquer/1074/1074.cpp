#include <bits/stdc++.h>

using namespace std;

int N, r, c;
int ans = 0;

void solve(int x, int y, int size)
{
    if (x == c && y == r)
    {
        cout << ans;
        return;
    }
    int half = size / 2;
    if (r < y + half && c < x + half)
    {
        solve(x, y, half);
    }
    else if (c >= x + half && r < y + half)
    {
        ans += half * half;
        solve(x + half, y, half);
    }
    else if (c < x + half && r >= y + half)
    {
        ans += 2 * half * half;
        solve(x, y + half, half);
    }
    else
    {
        ans += 3 * half * half;
        solve(x + half, y + half, half);
    }
}

int main()
{
    cin >> N >> r >> c;
    solve(0, 0, pow(2, N));
    return 0;
}