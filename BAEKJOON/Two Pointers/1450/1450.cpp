#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<long long> sums;

void generate_sums(int start, int end, long long current_sum)
{
    if (start == end)
    {
        sums.push_back(current_sum);
        return;
    }

    generate_sums(start + 1, end, current_sum);
    generate_sums(start + 1, end, current_sum + arr[start]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> sumA;
    sums.clear();
    generate_sums(0, n / 2, 0);
    sumA = sums;

    vector<long long> sumB;
    sums.clear();
    generate_sums(n / 2, n, 0);
    sumB = sums;

    sort(sumB.begin(), sumB.end());

    long long cnt = 0;

    for (long long a : sumA)
    {
        long long target = c - a;
        auto upper = upper_bound(sumB.begin(), sumB.end(), target);
        cnt += upper - sumB.begin();
    }

    cout << cnt << "\n";

    return 0;
}