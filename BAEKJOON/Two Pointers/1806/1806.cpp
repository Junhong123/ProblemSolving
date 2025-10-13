#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int start = 0;
    int end = 0;
    int minSize = n + 1;
    long long sum = 0;

    for (int end = 0; end < n; end++)
    {
        sum += v[end];

        while (sum >= s && start <= end)
        {
            minSize = min(minSize, end - start + 1);
            sum -= v[start++];
        }
    }

    if (minSize == n + 1)
        cout << "0\n";
    else
        cout << minSize << "\n";

    return 0;
}