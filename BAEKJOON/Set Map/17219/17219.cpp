#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    unordered_map<string, string> mp;
    string str1, str2;
    while (n--)
    {
        cin >> str1 >> str2;
        mp[str1] = str2;
    }

    while (m--)
    {
        cin >> str1;
        cout << mp[str1] << "\n";
    }

    return 0;
}