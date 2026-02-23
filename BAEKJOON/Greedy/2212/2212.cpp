#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (k >= n)
    {
        cout << 0;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; ++i)
        diff[i] = arr[i + 1] - arr[i];

    sort(diff.begin(), diff.end());
    while (--k)
        diff.pop_back();
    int ans = 0;
    for (auto &v : diff)
        ans += v;
    cout << ans;
    return 0;
}