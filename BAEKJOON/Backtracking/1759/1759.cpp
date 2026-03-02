#include <bits/stdc++.h>

using namespace std;

vector<char> arr;
string str;
int L, C;

bool comp()
{
    bool vowels = false;
    bool consonants = false;
    int consonants_cnt = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vowels = true;
        else
        {
            if (++consonants_cnt == 2)
                consonants = true;
        }
    }
    if (vowels && consonants)
        return true;
    return false;
}

void solve(int cur)
{
    if (str.size() == L)
    {
        if (comp())
        {
            cout << str << "\n";
        }
        return;
    }

    if (cur == C)
        return;

    str += arr[cur];
    solve(cur + 1);
    str.pop_back();
    solve(cur + 1);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    arr.resize(C);
    for (int i = 0; i < C; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    solve(0);

    return 0;
}