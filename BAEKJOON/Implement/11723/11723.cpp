#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    string str;
    cin >> m;
    int bit = 0;
    while (m--)
    {
        cin >> str;
        if (str == "add")
        {
            cin >> n;
            bit = bit | (1 << (n - 1));
        }
        else if (str == "remove")
        {
            cin >> n;
            bit = bit & ~(1 << (n - 1));
        }
        else if (str == "check")
        {
            cin >> n;
            if (bit & (1 << (n - 1)))
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (str == "toggle")
        {
            cin >> n;
            bit = bit ^ (1 << (n - 1));
        }
        else if (str == "all")
            bit = (1 << 20) - 1;
        else if (str == "empty")
            bit = 0;
    }

    return 0;
}