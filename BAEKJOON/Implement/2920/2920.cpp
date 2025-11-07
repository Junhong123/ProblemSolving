#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    bool asc = true;
    bool des = true;
    for (int i = 1; i <= 8; i++)
    {
        cin >> num;
        if (num != i)
            asc = false;
        if (num != 9 - i)
            des = false;
    }

    if (asc)
        cout << "ascending\n";
    else if (des)
        cout << "descending\n";
    else
        cout << "mixed\n";

    return 0;
}