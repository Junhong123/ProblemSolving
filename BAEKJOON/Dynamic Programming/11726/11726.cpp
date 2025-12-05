#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(1001);
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
        arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;

    cout << arr[n];

    return 0;
}

/*

    1 : 1
    2 : 2
    3 : 3
    4 : 5
    5 : 8
    6 : 13
    7 : 21
    8 : 34
    9 : 55

    x : x-2 + x-1

*/