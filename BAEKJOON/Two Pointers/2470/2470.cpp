#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int start = 0;
    int end = n - 1;
    vector<int> ans(2, 1000000001);

    while (start < end)
    {
        int sum = v[start] + v[end];
        if (abs(sum) < abs(ans[0] + ans[1]))
        {
            ans[0] = v[start];
            ans[1] = v[end];
        }
        if (sum == 0)
        {
            ans[0] = v[start];
            ans[1] = v[end];
            break;
        }
        else if (sum > 0)
            end--;
        else if (sum < 0)
            start++;
    }

    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}