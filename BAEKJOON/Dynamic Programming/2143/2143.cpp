#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, m;
    cin >> T;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    cin >> m;
    vector<int> B(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> B[i];

    vector<long long> sumA;
    for (int i = 1; i <= n; ++i)
    {
        long long sum = 0;
        for (int j = i; j <= n; ++j)
        {
            sum += A[j];
            sumA.emplace_back(sum);
        }
    }

    vector<long long> sumB;
    for (int i = 1; i <= m; ++i)
    {
        long long sum = 0;
        for (int j = i; j <= m; ++j)
        {
            sum += B[j];
            sumB.emplace_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());

    long long ans = 0;

    for (const auto &v : sumA)
    {
        auto up = upper_bound(sumB.begin(), sumB.end(), T - v);
        auto lb = lower_bound(sumB.begin(), sumB.end(), T - v);
        ans += up - lb;
    }

    cout << ans;

    return 0;
}