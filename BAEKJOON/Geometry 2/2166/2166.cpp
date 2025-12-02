#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    long long res1 = 0;
    long long res2 = 0;
    for (int i = 0; i < n; i++)
    {
        res1 += x[i] * y[(i + 1) % n];
        res2 += y[i] * x[(i + 1) % n];
    }
    double res = abs(res1 - res2) / 2.0;

    cout << fixed;
    cout.precision(1);
    cout << res << "\n";

    return 0;
}