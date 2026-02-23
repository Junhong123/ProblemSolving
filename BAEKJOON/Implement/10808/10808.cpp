#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    vector<int> arr(26, 0);
    cin >> str;
    for (auto &val : str)
        arr[val - 'a']++;
    for (auto &ans : arr)
        cout << ans << " ";

    return 0;
}