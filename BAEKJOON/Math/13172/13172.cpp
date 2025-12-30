#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> S(n);
    vector<int> N(n);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        cin >> N[i] >> S[i];
    for (int i = 0; i < n; ++i)
    {
        ll num = 1000000005;
        ll res = 1;
        ll b = N[i];
        while (num)
        {
            if (num & 1)
            {
                res *= b;
                res %= 1000000007;
            }
            b *= b;
            b %= 1000000007;
            num >>= 1;
        }
        ans += (res * S[i]) % 1000000007;
        ans %= 1000000007;
    }

    cout << ans;

    return 0;
}