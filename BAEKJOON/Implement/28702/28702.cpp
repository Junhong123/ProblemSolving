#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt, num;
    string str;
    for (int i = 3; i >= 1; i--)
    {
        cin >> str;

        if (str != "Fizz" && str != "Buzz" && str != "FizzBuzz")
        {
            num = stoi(str);
            cnt = i;
        }
    }

    int ans = num + cnt;

    if (ans % 3 == 0 && ans % 5 == 0)
        cout << "FizzBuzz";
    else if (ans % 3 == 0 && ans % 5 != 0)
        cout << "Fizz";
    else if (ans % 3 != 0 && ans % 5 == 0)
        cout << "Buzz";
    else
        cout << ans;

    cout << "\n";

    return 0;
}