#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int minus = round(n * 15.0 / 100.0);
    double sum = 0.;

    for (int i = minus; i < n - minus; i++)
        sum += arr[i];
    int res = round(sum / (n - (2 * minus)));

    cout << res;

    return 0;
}