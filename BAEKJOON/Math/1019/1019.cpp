#include <bits/stdc++.h>

using namespace std;

vector<long long> ans(10, 0);

void add(long long num, long long multiplier)
{
    while (num > 0)
    {
        ans[num % 10] += multiplier;
        num /= 10;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long start = 1;
    long long end = n;
    long long multiplier = 1;

    while (start <= end)
    {
        while (start % 10 != 0 && start <= end)
        {
            add(start, multiplier);
            start++;
        }

        if (start > end)
            break;

        while (end % 10 != 9 && start <= end)
        {
            add(end, multiplier);
            end--;
        }

        int cnt = (end / 10 - start / 10 + 1);
        for (int i = 0; i < 10; ++i)
            ans[i] += cnt * multiplier;

        start /= 10;
        end /= 10;
        multiplier *= 10;
    }

    for (auto &v : ans)
        cout << v << " ";

    return 0;
}