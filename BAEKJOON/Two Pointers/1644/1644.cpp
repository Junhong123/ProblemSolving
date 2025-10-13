#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    vector<int> v;
    vector<bool> is_prime(num + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= num; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= num; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i <= num; i++)
    {
        if (is_prime[i])
            v.emplace_back(i);
    }

    int start = 0;
    int cnt = 0;
    int sum = 0;

    for (int end = 0; end < v.size(); end++)
    {
        sum += v[end];

        while (sum >= num)
        {
            if (sum == num)
                cnt++;
            sum -= v[start++];
        }
    }

    cout << cnt << "\n";

    return 0;
}