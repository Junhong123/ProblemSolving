#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr1;
    vector<int> arr2;
    int n;
    cin >> n;

    for (int i = n; i > 0; i -= 3)
    {
        if (i > 2)
        {
            if (arr1.size() >= arr2.size())
            {
                arr1.emplace_back(i);
                arr2.emplace_back(i - 1);
                arr2.emplace_back(i - 2);
            }
            else
            {
                arr2.emplace_back(i);
                arr1.emplace_back(i - 1);
                arr1.emplace_back(i - 2);
            }
        }
        else if (i == 2)
        {
            arr1.emplace_back(1);
            arr2.emplace_back(2);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    cout << arr1.size() << "\n";
    for (auto &ans : arr1)
        cout << ans << " ";
    cout << "\n"
         << arr2.size() << "\n";
    for (auto &ans : arr2)
        cout << ans << " ";
    cout << "\n";

    return 0;
}