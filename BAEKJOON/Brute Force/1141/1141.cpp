#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int sz = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        if (!arr[i + 1].starts_with(arr[i]))
        {
            sz++;
        }
    }

    cout << sz;
    return 0;
}