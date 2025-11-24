#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
int cnt = 1;

tuple<int, int, int, int> make_box(int s_x, int s_y, bool rev)
{
    int nx1, nx2, ny1, ny2;

    if (rev)
    {
        if (s_x % 2 == 0)
        {
            nx1 = s_x - 1;
            nx2 = s_x;
        }
        else
        {
            nx1 = s_x;
            nx2 = s_x + 1;
        }

        if (s_y % 2 == 0)
        {
            ny1 = s_y - 1;
            ny2 = s_y;
        }
        else
        {
            ny1 = s_y;
            ny2 = s_y + 1;
        }
    }
    else
    {
        if (s_x % 2 == 0)
        {
            nx1 = s_x;
            nx2 = s_x + 1;
        }
        else
        {
            nx1 = s_x - 1;
            nx2 = s_x;
        }

        if (s_y % 2 == 0)
        {
            ny1 = s_y;
            ny2 = s_y + 1;
        }
        else
        {
            ny1 = s_y - 1;
            ny2 = s_y;
        }
    }

    return {nx1, nx2, ny1, ny2};
}

void fill_4(int x1, int x2, int y1, int y2, int s_x, int s_y)
{
    int x[2] = {x1, x2};
    int y[2] = {y1, y2};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (x[i] != s_x || y[j] != s_y)
                arr[y[j]][x[i]] = cnt;
        }
    }

    cnt++;
}

void fill_16(int x1, int x2, int y1, int y2, int s_x, int s_y)
{
    auto [nx1, nx2, ny1, ny2] = make_box(s_x, s_y, true);

    fill_4(nx1, nx2, ny1, ny2, s_x, s_y);

    int m_x, m_y;
    if (nx2 == x2)
        m_x = nx1;
    else
        m_x = nx2;
    if (ny2 == y2)
        m_y = ny1;
    else
        m_y = ny2;

    auto [mx1, mx2, my1, my2] = make_box(m_x, m_y, false);
    fill_4(mx1, mx2, my1, my2, m_x, m_y);
    int mx[2] = {mx1, mx2};
    int my[2] = {my1, my2};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (mx[i] != m_x || my[j] != m_y)
            {
                auto [tx1, tx2, ty1, ty2] = make_box(mx[i], my[j], true);
                fill_4(tx1, tx2, ty1, ty2, mx[i], my[j]);
            }
        }
    }
}

void solve(int x1, int x2, int y1, int y2, int s_x, int s_y)
{
    int size = x2 - x1 + 1;
    if (size > 4)
    {
        pair<int, int> x[2] = {{x1, x2 / 2}, {x2 / 2, x2}};
        pair<int, int> y[2] = {{y1, y2 / 2}, {y2 / 2, y2}};
        pair<int, int> tmp;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (s_x > x[i].first && s_x < x[i].second && s_y > y[j].first && s_y < y[j].second)
                {
                    solve(x[i].first, x[i].second, y[j].first, y[i].second, s_x, s_y);
                    tmp = {s_x, s_y};
                }
                else
                {
                }
            }
        }
    }
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;

    int size = pow(2, k);
    arr.resize(size + 1, vector<int>(size + 1, 0));
    arr[y][x] = -1;

    if (k == 1)
    {
        fill_4(1, size, 1, size, x, y);
    }
    else
    {
        fill_16(1, size, 1, size, x, y);
    }

    for (int i = size; i > 0; i--)
    {
        for (int j = 1; j <= size; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}