#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr(3);

    for (int i = 0; i < 3; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (auto &ans : arr)
        cout << ans << " ";
    cout << "\n";

    return 0;
}