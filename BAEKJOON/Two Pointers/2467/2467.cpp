#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int start = 0;
    int end = n - 1;
    int ans[2];
    int min_n = INT_MAX;
    while (start < end)
    {
        sum = arr[start] + arr[end];
        if (min_n > abs(sum))
        {
            ans[0] = arr[start];
            ans[1] = arr[end];
            min_n = abs(sum);
        }
        if (sum > 0)
            end--;
        else if (sum < 0)
            start++;
        else
            break;
    }

    cout << ans[0] << " " << ans[1];

    return 0;
}