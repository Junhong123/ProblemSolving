#include <bits/stdc++.h>

using namespace std;

int r, c, t;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int>> arr;
vector<int> air;

void diff()
{
    vector<vector<int>> tmp_arr(r, vector<int>(c));
    copy(arr.begin(), arr.end(), tmp_arr.begin());
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (arr[i][j] != 0 && arr[i][j] != -1)
            {
                int val = arr[i][j] / 5;
                for (int k = 0; k < 4; ++k)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny >= 0 && ny < r && nx >= 0 && nx < c && arr[ny][nx] != -1)
                    {
                        tmp_arr[ny][nx] += val;
                        tmp_arr[i][j] -= val;
                    }
                }
            }
        }
    }
    copy(tmp_arr.begin(), tmp_arr.end(), arr.begin());
}

void purify()
{
    int ny1 = air[0];
    int ny2 = air[1];
    int tmp;
    int prev = arr[ny1][1];
    arr[ny1][1] = 0;
    for (int i = 2; i < c; ++i)
    {
        tmp = arr[ny1][i];
        arr[ny1][i] = prev;
        prev = tmp;
    }
    for (int i = ny1 - 1; i >= 0; --i)
    {
        tmp = arr[i][c - 1];
        arr[i][c - 1] = prev;
        prev = tmp;
    }
    for (int i = c - 2; i >= 0; --i)
    {
        tmp = arr[0][i];
        arr[0][i] = prev;
        prev = tmp;
    }
    for (int i = 1; i < ny1; ++i)
    {
        tmp = arr[i][0];
        arr[i][0] = prev;
        prev = tmp;
    }

    prev = arr[ny2][1];
    arr[ny2][1] = 0;

    for (int i = 2; i < c; ++i)
    {
        tmp = arr[ny2][i];
        arr[ny2][i] = prev;
        prev = tmp;
    }
    for (int i = ny2 + 1; i < r; ++i)
    {
        tmp = arr[i][c - 1];
        arr[i][c - 1] = prev;
        prev = tmp;
    }
    for (int i = c - 2; i >= 0; --i)
    {
        tmp = arr[r - 1][i];
        arr[r - 1][i] = prev;
        prev = tmp;
    }
    for (int i = r - 2; i > ny2; --i)
    {
        tmp = arr[i][0];
        arr[i][0] = prev;
        prev = tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    arr.resize(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
                air.emplace_back(i);
        }
    }

    while (t--)
    {
        diff();
        purify();
    }

    int ans = 0;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (arr[i][j] != -1)
                ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}