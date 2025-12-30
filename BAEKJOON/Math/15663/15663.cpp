#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
vector<int> result;
vector<bool> is_Used;

void solve()
{
    if (result.size() == m)
    {
        for (auto &val : result)
        {
            cout << val << " ";
        }
        cout << "\n";
        return;
    }

    int last_val = -1;

    for (int i = 0; i < n; i++)
    {
        if (!is_Used[i] && arr[i] != last_val)
        {
            result.push_back(arr[i]);
            is_Used[i] = true;
            last_val = arr[i];

            solve();

            result.pop_back();
            is_Used[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    is_Used.resize(n, false);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    solve();
    return 0;
}