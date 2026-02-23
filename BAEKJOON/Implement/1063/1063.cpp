#include <bits/stdc++.h>

using namespace std;

pair<int, int> king;
pair<int, int> stone;

void solve(pair<int, int> target)
{
    pair<int, int> tmp_king = {king.first + target.first, king.second + target.second};
    pair<int, int> tmp_stone = stone;
    if (tmp_king == stone)
        tmp_stone = {stone.first + target.first, stone.second + target.second};

    if (
        tmp_stone.first >= 0 && tmp_stone.first < 8 &&
        tmp_stone.second > 0 && tmp_stone.second < 9 &&
        tmp_king.first >= 0 && tmp_king.first < 8 &&
        tmp_king.second > 0 && tmp_king.second < 9)
    {
        king = tmp_king;
        stone = tmp_stone;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    char k, s;
    int kn, sn, n;
    cin >> k >> kn >> s >> sn >> n;
    king = {k - 'A', kn};
    stone = {s - 'A', sn};
    while (n--)
    {
        cin >> str;
        pair<int, int> target;
        if (str == "R")
            target = {1, 0};
        else if (str == "L")
            target = {-1, 0};
        else if (str == "B")
            target = {0, -1};
        else if (str == "T")
            target = {0, 1};
        else if (str == "RT")
            target = {1, 1};
        else if (str == "LT")
            target = {-1, 1};
        else if (str == "RB")
            target = {1, -1};
        else if (str == "LB")
            target = {-1, -1};
        solve(target);
    }

    cout << (char)(king.first + 'A') << king.second << "\n";
    cout << (char)(stone.first + 'A') << stone.second << "\n";

    return 0;
}