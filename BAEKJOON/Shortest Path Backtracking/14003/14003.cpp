#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> M(n + 1, 0);
    vector<int> path(n, -1);
    int L = 0;

    for (int i = 0; i < n; i++)
    {
        int lo = 1;
        int hi = L;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[M[mid]] < arr[i])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        int newL = lo;
        path[i] = M[newL - 1];
        M[newL] = i;
        if (newL > L)
            L = newL;
    }

    vector<int> res(L);
    int k = M[L];
    for (int i = L - 1; i >= 0; i--)
    {
        res[i] = arr[k];
        k = path[k];
    }

    cout << L << "\n";
    for (int val : res)
        cout << val << " ";
    cout << "\n";

    return 0;
}