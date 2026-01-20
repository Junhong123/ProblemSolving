#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<long long>> arr(4, vector<long long>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> arr[j][i];
        }
    }

    vector<long long> sumA;
    vector<long long> sumB;
    long long asum = 0;
    long long bsum = 0;

    for (int i = 0; i < n; ++i)
    {
        asum = arr[0][i];
        bsum = arr[2][i];
        for (int j = 0; j < n; ++j)
        {
            asum += arr[1][j];
            sumA.emplace_back(asum);
            asum -= arr[1][j];

            bsum += arr[3][j];
            sumB.emplace_back(bsum);
            bsum -= arr[3][j];
        }
    }

    sort(sumB.begin(), sumB.end());

    long long ans = 0;
    for (auto &v : sumA)
    {
        long long target = -v;
        ans += upper_bound(sumB.begin(), sumB.end(), target) - lower_bound(sumB.begin(), sumB.end(), target);
    }

    cout << ans;

    return 0;
}