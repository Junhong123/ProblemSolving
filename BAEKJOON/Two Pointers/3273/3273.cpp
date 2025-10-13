#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int c;
    cin >> c;

    sort(v.begin(), v.end());

    int start = 0;
    int end = n - 1;
    int tot = 0;

    while (start < end)
    {
        int sum = v[start] + v[end];
        if (sum == c)
        {
            tot++;
            start++;
        }
        else if (sum > c)
            end--;
        else if (sum < c)
            start++;
    }

    cout << tot << "\n";

    return 0;
}