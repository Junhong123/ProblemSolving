#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    ans += n / 5;
    ans += n / 25;
    ans += n / 125;

    cout << ans;

    return 0;
}