#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, tmp, cnt;
    while (cin >> n)
    {
        tmp = 1;
        cnt = 1;
        while (tmp % n != 0)
        {
            tmp = (tmp * 10 + 1) % n;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}