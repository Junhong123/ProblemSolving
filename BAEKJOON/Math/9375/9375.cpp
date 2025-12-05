#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        map<string, int> mp;
        vector<string> arr;

        for (int i = 0; i < n; i++)
        {
            string str1, str2;
            cin >> str1 >> str2;
            if (mp.find(str2) == mp.end())
            {
                arr.emplace_back(str2);
                mp[str2] = 2;
            }
            else
                mp[str2]++;
        }

        int ans = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            ans *= mp[arr[i]];
        }

        cout << ans - 1 << "\n";
    }
    return 0;
}