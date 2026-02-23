#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, F, ans;
    cin >> N >> F;

    N = N - (N % 100) - 1;
    for (int i = 0; i < 100; ++i)
    {
        N++;
        if (N % F == 0)
        {
            ans = i;
            break;
        }
    }

    if (ans < 10)
        cout << 0 << ans << "\n";
    else
        cout << ans << "\n";

    return 0;
}