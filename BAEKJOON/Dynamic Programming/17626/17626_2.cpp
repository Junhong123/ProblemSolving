#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    iota(arr.begin(), arr.end(), 0);

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            arr[i] = min(arr[i], arr[i - j * j] + 1);
        }
    }

    cout << arr[n];

    return 0;
}