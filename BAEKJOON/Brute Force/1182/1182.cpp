#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    int ans = 0;
    cin >> n >> s;
    vector<int> arr(n);
    vector<int> selected(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int len = 1; len <= n; ++len)
    {
        for (int i = 0; i < len; ++i)
            selected[i] = 0;
        for (int i = len; i < n; ++i)
            selected[i] = 1;

        do
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (!selected[i])
                    sum += arr[i];
            }
            if (sum == s)
                ans++;
        } while (next_permutation(selected.begin(), selected.end()));
    }

    cout << ans;

    return 0;
}