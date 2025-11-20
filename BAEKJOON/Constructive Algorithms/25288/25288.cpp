#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++)
        for (char &ans : str)
            cout << ans;
    cout << "\n";

    return 0;
}