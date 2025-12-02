#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int ans = 0; ans <= 9; ans++)
    {
        int sum = 0;

        for (int i = 0; i < 13; i++)
        {
            int digit, mult;

            if (i % 2 == 0)
                mult = 1;
            else
                mult = 3;

            if (str[i] == '*')
                digit = ans;
            else
                digit = str[i] - '0';

            sum += digit * mult;
        }

        if (sum % 10 == 0)
        {
            cout << ans << "\n";
            return 0;
        }
    }

    return 0;
}