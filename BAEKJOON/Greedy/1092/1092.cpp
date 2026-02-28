#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> crn(n);
    for (int i = 0; i < n; ++i)
        cin >> crn[i];

    cin >> m;
    vector<int> weights(m);
    for (int i = 0; i < m; ++i)
        cin >> weights[i];

    sort(crn.begin(), crn.end());
    sort(weights.begin(), weights.end());
    if (crn[n - 1] < weights[m - 1])
    {
        cout << -1 << "\n";
        return 0;
    }

    int cnt = 0;
    while (weights.size() != 0)
    {
        cnt++;
        for (auto &cr : crn)
        {
            if (weights.empty())
                break;
            auto it = upper_bound(weights.begin(), weights.end(), cr);
            if (it != weights.begin())
            {
                it -= 1;
                weights.erase(it);
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}