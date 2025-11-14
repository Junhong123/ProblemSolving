#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(6);
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    int t, p;
    cin >> t >> p;
    int ans = 0;

    for (auto &val : arr)
    {
        if (val % t == 0)
            ans += val / t;
        else
            ans += val / t + 1;
    }
    cout << ans << "\n";
    cout << n / p << " " << n % p << "\n";
    return 0;
}