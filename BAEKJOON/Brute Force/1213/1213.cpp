#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    vector<int> cnt(26, 0);
    for (int i = 0; i < str.length(); ++i)
    {
        cnt[str[i] - 'A']++;
    }

    int odd_cnt = 0;
    char mid;

    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] % 2 != 0)
        {
            odd_cnt++;
            mid = i + 'A';
        }
    }

    if (odd_cnt > 1)
    {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    string half_str = "";
    for (int i = 0; i < 26; ++i)
    {
        half_str += string(cnt[i] / 2, i + 'A');
    }

    string result = half_str;
    if (odd_cnt == 1)
        result += mid;

    reverse(half_str.begin(), half_str.end());
    result += half_str;

    cout << result << "\n";

    return 0;
}