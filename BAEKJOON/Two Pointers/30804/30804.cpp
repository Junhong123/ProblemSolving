#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> cnt(11, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0;
    int right = 0;
    int kind = 0;
    int ans = 0;

    for (right = 0; right < n; right++)
    {
        if (cnt[arr[right]]++ == 0)
            kind++;

        while (kind > 2)
        {
            if (--cnt[arr[left++]] == 0)
                kind--;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans << "\n";

    return 0;
}