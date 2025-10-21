#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int h, w, n;
        cin >> h >> w >> n;
        if (h == 1)
            cout << "1";
        else if (n % h != 0)
            cout << n % h;
        else
            cout << h;

        if (h == 1 || n % h == 0)
        {
            if (n / h >= 10)
                cout << n / h;
            else
                cout << "0" << n / h;
        }
        else
        {
            if (n / h + 1 >= 10)
                cout << n / h + 1;
            else
                cout << "0" << n / h + 1;
        }
        cout << "\n";
    }

    return 0;
}