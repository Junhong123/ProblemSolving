#include <bits/stdc++.h>

using namespace std;

bool broken[10];

int possible(int num)
{
    if (num == 0)
    {
        return broken[0] ? 0 : 1;
    }

    int len = 0;
    while (num > 0)
    {
        if (broken[num % 10])
        {
            return 0;
        }
        len += 1;
        num /= 10;
    }
    return len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int b;
        cin >> b;
        broken[b] = true;
    }

    int ans = abs(n - 100);

    for (int i = 0; i <= 1000000; ++i)
    {
        int len = possible(i);

        if (len > 0)
        {
            int press = abs(n - i);
            if (ans > len + press)
            {
                ans = len + press;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}