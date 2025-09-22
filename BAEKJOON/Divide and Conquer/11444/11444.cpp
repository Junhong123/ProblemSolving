#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> multiply(const vector<vector<ll>> &v1, const vector<vector<ll>> &v2, int n, int m, int r)
{
    vector<vector<ll>> res(n, vector<ll>(r, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < m; k++)
            {
                res[i][j] += v1[i][k] * v2[k][j];
            }
            res[i][j] %= 1000000007;
        }
    }

    return res;
}

vector<vector<ll>> power(const vector<vector<ll>> &v, long long b)
{
    if (b == 0)
    {
        vector<vector<ll>> tmp(2, vector<ll>(2, 0));
        tmp[0][0] = tmp[1][1] = 1;
        return tmp;
    }
    if (b == 1)
        return v;

    int s = v.size();
    vector<vector<ll>> half = power(v, b / 2);
    vector<vector<ll>> res = multiply(half, half, s, s, s);

    if (b % 2 == 1)
    {
        res = multiply(res, v, s, s, s);
    }

    return res;
}

int main()
{
    long long n;

    cin >> n;

    vector<vector<ll>> Fmat(2, vector<ll>(2, 1));
    Fmat[1][1] = 0;

    vector<vector<ll>> Fib(2, vector<ll>(1, 0));
    Fib[0][0] = 1;

    vector<vector<ll>> res = power(Fmat, n - 1);

    res = multiply(res, Fib, 2, 2, 1);

    cout << res[0][0] << "\n";

    return 0;
}