#include <bits/stdc++.h>

using namespace std;

int arr[130][130];
int cnt = 0;

void solve(int x, int y, int size, int sx, int sy)
{
    if (size == 1)
        return;

    cnt++;
    int cur_cnt = cnt;
    int half = size / 2;

    if (sx >= x + half && sy >= y + half)
    {
        solve(x + half, y + half, half, sx, sy);
    }
    else
    {
        arr[y + half][x + half] = cur_cnt;
        solve(x + half, y + half, half, x + half, y + half);
    }

    if (sx < x + half && sy >= y + half)
    {
        solve(x, y + half, half, sx, sy);
    }
    else
    {
        arr[y + half][x + half - 1] = cur_cnt;
        solve(x, y + half, half, x + half - 1, y + half);
    }

    if (sx < x + half && sy < y + half)
    {
        solve(x, y, half, sx, sy);
    }
    else
    {
        arr[y + half - 1][x + half - 1] = cur_cnt;
        solve(x, y, half, x + half - 1, y + half - 1);
    }

    if (sx >= x + half && sy < y + half)
    {
        solve(x + half, y, half, sx, sy);
    }
    else
    {
        arr[y + half - 1][x + half] = cur_cnt;
        solve(x + half, y, half, x + half, y + half - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, x, y;
    cin >> k >> x >> y;

    int size = (1 << k);

    arr[y][x] = -1;

    solve(1, 1, size, x, y);

    for (int i = size; i >= 1; i--)
    {
        for (int j = 1; j <= size; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}