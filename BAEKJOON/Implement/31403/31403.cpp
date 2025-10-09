#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, c;

    cin >> a >> b >> c;

    int ia = stoi(a);
    int ib = stoi(b);
    int ic = stoi(c);

    a.append(b);
    int num = stoi(a);

    cout << ia + ib - ic << "\n";

    cout << num - ic << "\n";

    return 0;
}