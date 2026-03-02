#include <bits/stdc++.h>

using namespace std;

vector<long long> nums;

void solve(long long cur)
{
    nums.emplace_back(cur);
    int last_digit = cur % 10;

    for (int i = 0; i < last_digit; ++i)
    {
        solve(cur * 10 + i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i <= 9; ++i)
        solve(i);

    sort(nums.begin(), nums.end());

    if (n >= nums.size())
        cout << -1 << "\n";
    else
        cout << nums[n] << "\n";

    return 0;
}