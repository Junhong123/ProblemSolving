#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<double, double>> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int y, x;
        cin >> y >> x;
        arr[i] = {y, x};
    }
    double ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                auto [x1, y1] = arr[i];
                auto [x2, y2] = arr[j];
                auto [x3, y3] = arr[k];
                ans = max(ans, abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2);
            }
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << ans << "\n";

    return 0;
}