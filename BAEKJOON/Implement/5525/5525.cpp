#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int cnt = 0;
    int ans = 0;
    string str;
    cin >> n >> m >> str;
    for (int i = 0; i < m - 2; i++)
    {
        if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
        {
            cnt++;
            if (cnt >= n)
            {
                cnt--;
                ans++;
            }
            i++;
        }
        else
            cnt = 0;
    }

    cout << ans;

    return 0;
}