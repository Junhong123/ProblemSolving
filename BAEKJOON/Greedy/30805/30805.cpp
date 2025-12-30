#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<int> res;
    int idx1 = 0;
    int idx2 = 0;

    while (true)
    {
        int max_n = -1;
        for (int v = 100; v > 0; --v)
        {
            bool is1 = false;
            bool is2 = false;

            for (int i = idx1; i < n; ++i)
            {
                if (arr1[i] == v)
                {
                    is1 = true;
                    break;
                }
            }

            for (int i = idx2; i < m; ++i)
            {
                if (arr2[i] == v)
                {
                    is2 = true;
                    break;
                }
            }

            if (is1 && is2)
            {
                max_n = v;
                break;
            }
        }

        if (max_n == -1)
            break;

        res.push_back(max_n);

        for (int i = idx1; i < n; i++)
        {
            if (arr1[i] == max_n)
            {
                idx1 = i + 1;
                break;
            }
        }

        for (int j = idx2; j < m; j++)
        {
            if (arr2[j] == max_n)
            {
                idx2 = j + 1;
                break;
            }
        }
    }

    cout << res.size() << "\n";
    if (!res.empty())
    {
        for (auto &v : res)
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}