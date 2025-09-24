#include <bits/stdc++.h>

using namespace std;

int bs(const vector<int> &v, int start, int end, int target)
{
    int mid = (start + end) / 2;
    if (start > end)
        return 0;
    else if (v[mid] == target)
        return 1;

    if (v[mid] > target)
    {
        return bs(v, start, mid - 1, target);
    }
    else
    {
        return bs(v, mid + 1, end, target);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cin >> m;

    while (m--)
    {
        int num;
        cin >> num;
        cout << bs(v, 0, v.size() - 1, num) << "\n";
    }

    return 0;
}