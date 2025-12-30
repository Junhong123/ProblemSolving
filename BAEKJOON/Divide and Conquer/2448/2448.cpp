#include <bits/stdc++.h>

using namespace std;

char board[3072][6144];

void solve(int n, int y, int x)
{
    if (n == 3)
    {
        board[y][x] = '*';
        board[y + 1][x - 1] = '*';
        board[y + 1][x + 1] = '*';
        for (int i = 0; i < 5; i++)
            board[y + 2][x - 2 + i] = '*';
    }
    else
    {
        int half = n / 2;
        solve(half, y, x);
        solve(half, y + half, x - half);
        solve(half, y + half, x + half);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            board[i][j] = ' ';
        }
    }

    solve(n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}