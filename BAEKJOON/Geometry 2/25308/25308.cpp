#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isConvex(const vector<int> &v)
{
    for (int i = 0; i < 8; i++)
    {
        ll a = v[(i + 7) % 8];
        ll b = v[i];
        ll c = v[(i + 1) % 8];

        ll left = b * b * (a + c) * (a + c);
        ll right = 2 * (a * c) * (a * c);

        if (left < right)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> stats(8);
    for (int i = 0; i < 8; i++)
        cin >> stats[i];

    vector<int> idxs(8);
    iota(idxs.begin(), idxs.end(), 0);

    int count = 0;
    do
    {
        vector<int> curr(8);
        for (int i = 0; i < 8; i++)
            curr[i] = stats[idxs[i]];
        if (isConvex(curr))
        {
            count++;
        }
    } while (next_permutation(idxs.begin(), idxs.end()));

    cout << count << "\n";

    return 0;
}