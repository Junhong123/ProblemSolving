#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
vector<int> result;

void solve(int start)
{
    if (result.size() == m)
    {
        for (auto &val : result)
            cout << val << " ";
        cout << "\n";
        return;
    }

    int recent = -1;

    for (int i = start; i < n; i++)
    {
        if (recent != arr[i])
        {
            result.push_back(arr[i]);
            recent = arr[i];
            solve(i);
            result.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    solve(0);
    return 0;
}