#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> number;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        number.emplace_back(num);
    }

    int res = 0;
    for (auto num : number)
    {
        res += pow(num, 2);
    }
    res %= 10;
    cout << res << "\n";
    return 0;
}