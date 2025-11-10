#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> l;
    l.resize(3);
    while (1)
    {
        for (int i = 0; i < 3; i++)
            cin >> l[i];
        if (l[0] == 0 && l[1] == 0 && l[2] == 0)
            break;
        sort(l.begin(), l.end());
        if (pow(l[2], 2) == pow(l[0], 2) + pow(l[1], 2))
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}