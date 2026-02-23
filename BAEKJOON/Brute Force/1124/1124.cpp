#include <bits/stdc++.h>

using namespace std;

vector<int> min_factor(100001);
vector<bool> isPrime(100001, true);

int solve(int n)
{
    if (isPrime[n])
        return 1;
    else if (n == 1)
        return 0;
    return solve(n / min_factor[n]) + 1;
}

int main()
{
    int A, B;
    cin >> A >> B;
    isPrime[1] = false;
    for (int i = 2; i <= B; ++i)
    {
        if (isPrime[i])
        {
            min_factor[i] = i;
            for (int j = i * 2; j <= B; j += i)
            {
                if (isPrime[j])
                {
                    isPrime[j] = false;
                    min_factor[j] = i;
                }
            }
        }
    }

    int ans = 0;
    for (int i = A; i <= B; ++i)
    {
        if (isPrime[solve(i)])
            ans++;
    }

    cout << ans;

    return 0;
}