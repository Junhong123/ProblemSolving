#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        int left = i;
        int right = str.length() - 1;
        bool comp = true;

        while (left < right)
        {
            if (str[left] != str[right])
            {
                comp = false;
                break;
            }
            left++;
            right--;
        }

        if (comp)
        {
            cout << str.length() + i << "\n";
            return 0;
        }
    }

    return 0;
}