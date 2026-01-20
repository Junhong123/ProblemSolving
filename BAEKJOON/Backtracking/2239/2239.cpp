#include <bits/stdc++.h>

using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;
bool row[9][10];
bool col[9][10];
bool box[9][10];

int find_box(int r, int c)
{
    return (r / 3) * 3 + (c / 3);
}

void print_board()
{
    for (auto &r : board)
    {
        for (auto &v : r)
        {
            cout << v;
        }
        cout << "\n";
    }
}

void dfs(int idx)
{
    if (idx == blanks.size())
    {
        print_board();
        exit(0);
    }

    int r = blanks[idx].first;
    int c = blanks[idx].second;
    int box_idx = find_box(r, c);
    for (int i = 1; i <= 9; i++)
    {
        if (!row[r][i] && !col[c][i] && !box[box_idx][i])
        {
            row[r][i] = true;
            col[c][i] = true;
            box[box_idx][i] = true;
            board[r][c] = i;

            dfs(idx + 1);

            row[r][i] = false;
            col[c][i] = false;
            box[box_idx][i] = false;
            board[r][c] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tmp;
    for (int i = 0; i < 9; i++)
    {
        cin >> tmp;
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = tmp[j] - '0';
            if (board[i][j] != 0)
            {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                box[find_box(i, j)][board[i][j]] = true;
            }
            else
                blanks.emplace_back(i, j);
        }
    }

    dfs(0);

    return 0;
}