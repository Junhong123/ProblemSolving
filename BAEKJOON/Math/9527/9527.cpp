#include <bits/stdc++.h>

using namespace std;

long long solve(long long n)
{
    if (n == 1)
        return 1;
    else if (n <= 0)
        return 0;

    long long cur = 2;
    int k = 1;
    while (cur <= n)
    {
        k++;
        cur *= 2;
    }
    k--;
    long long ans = k * (1LL << (k - 1));
    long long rest = n - (1LL << (k));
    ans += rest + 1;
    return ans + solve(rest);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a - 1);

    return 0;
}