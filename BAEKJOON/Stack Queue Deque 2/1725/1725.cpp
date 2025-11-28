#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int solve(int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid + 1, right));
    int lo = mid;
    int hi = mid + 1;
    int height = min(arr[lo], arr[hi]);
    ret = max(ret, height * 2);

    while (lo > left || hi < right)
    {
        if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1]))
        {
            height = min(height, arr[++hi]);
        }
        else
        {
            height = min(height, arr[--lo]);
        }

        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(0, n - 1) << "\n";

    return 0;
}