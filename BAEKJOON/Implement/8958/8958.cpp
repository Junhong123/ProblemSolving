#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        int cnt = 0;
        int ans = 0;
        for (auto &c : str)
        {
            if (c == 'O')
                ans += ++cnt;
            else
                cnt = 0;
        }
        cout << ans << "\n";
    }

    return 0;
}