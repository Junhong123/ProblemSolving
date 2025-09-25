#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    int num;
    int idx = 0;
    cin >> num;
    v[idx++] = num;

    for (int i = 1; i < n; i++)
    {
        cin >> num;
        if (v[idx - 1] < num)
        {
            v[idx++] = num;
        }
        else
        {
            auto it = lower_bound(v.begin(), v.begin() + idx, num);
            *it = num;
        }
    }

    cout << idx << "\n";

    return 0;
}