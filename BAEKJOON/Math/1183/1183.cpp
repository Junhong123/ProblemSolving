#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> D(n);
    for (int i = 0; i < n; ++i)
    {
        long long A, B;
        cin >> A >> B;
        D[i] = B - A;
    }

    sort(D.begin(), D.end());

    if (n % 2 == 1)
    {
        cout << 1 << "\n";
    }
    else
    {
        long long cnt = D[n / 2] - D[n / 2 - 1] + 1;
        cout << cnt << "\n";
    }

    return 0;
}