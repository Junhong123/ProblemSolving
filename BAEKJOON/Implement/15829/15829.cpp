#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    long long ans = 0;
    long long r = 1;
    long long M = 1234567891;

    for (int i = 0; i < n; i++)
    {
        long long val = str[i] - 'a' + 1;
        ans = (ans + (val * r)) % M;
        r = (r * 31) % M;
    }

    cout << ans << "\n";

    return 0;
}