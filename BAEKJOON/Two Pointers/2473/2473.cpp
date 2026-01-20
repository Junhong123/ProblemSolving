#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool isC = false;
    int n, start, end;
    long long mn = LLONG_MAX;
    long long sum;
    long long ans[3];
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int fixed = 0; fixed < n - 2; fixed++)
    {
        start = fixed + 1;
        end = n - 1;
        while (start < end)
        {
            sum = arr[fixed] + arr[start] + arr[end];
            if (abs(sum) < mn)
            {
                mn = abs(sum);
                ans[0] = arr[fixed];
                ans[1] = arr[start];
                ans[2] = arr[end];
            }
            if (sum == 0)
            {
                isC = true;
                break;
            }
            else if (sum > 0)
                end--;
            else if (sum < 0)
                start++;
        }
        if (isC)
            break;
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}