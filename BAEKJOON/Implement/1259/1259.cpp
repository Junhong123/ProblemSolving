#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    while (str != "0")
    {
        bool isP = true;
        for (int i = 0; i < str.size() / 2; i++)
        {
            int idx = str.size() - i - 1;
            if (str[i] != str[idx])
                isP = false;
        }

        if (isP)
            cout << "yes\n";
        else
            cout << "no\n";

        cin >> str;
    }

    return 0;
}