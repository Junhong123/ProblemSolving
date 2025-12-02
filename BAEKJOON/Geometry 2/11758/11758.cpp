#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    int res = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]);

    if (res > 0)
        cout << "1\n";
    else if (res < 0)
        cout << "-1\n";
    else
        cout << "0\n";

    return 0;
}