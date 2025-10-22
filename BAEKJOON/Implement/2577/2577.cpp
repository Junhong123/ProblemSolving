#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int mul = n1 * n2 * n3;
    vector<int> ans(10, 0);

    while (mul > 0)
    {
        int idx = mul % 10;
        ans[idx]++;
        mul /= 10;
    }

    for (auto val : ans)
        cout << val << "\n";

    return 0;
}