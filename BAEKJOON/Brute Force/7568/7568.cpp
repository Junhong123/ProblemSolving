#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].first > arr[j].first && arr[i].second > arr[j].second)
                ans[j]++;
            else if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                ans[i]++;
        }
    }

    for (auto &val : ans)
        cout << val << " ";
    cout << "\n";

    return 0;
}