#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        long long x, y;
        cin >> x >> y;

        long long dist = y - x;

        long long root = (long long)sqrt(dist);

        if (root * root == dist)
        {
            cout << 2 * root - 1 << "\n";
        }
        else if (dist <= root * root + root)
        {
            cout << 2 * root << "\n";
        }
        else
        {
            cout << 2 * root + 1 << "\n";
        }
    }

    return 0;
}