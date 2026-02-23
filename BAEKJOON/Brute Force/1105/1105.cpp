#include <bits/stdc++.h>

using namespace std;

int main()
{
    string L, R;
    cin >> L >> R;

    if (L.length() != R.length())
    {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < L.length(); ++i)
    {
        if (L[i] == R[i])
        {
            if (L[i] == '8')
                ans++;
        }
        else
            break;
    }

    cout << ans << "\n";
    return 0;
}