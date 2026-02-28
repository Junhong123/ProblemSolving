#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num, root;
    cin >> n;
    vector<int> arr(n);
    vector<int> child(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[i] != -1)
        {
            child[arr[i]]++;
        }
        else
        {
            root = i;
        }
    }

    cin >> num;
    if (num == root)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> deleted;
    deleted.emplace_back(num);
    bool comp = false;
    while (!comp)
    {
        comp = true;
        for (int i = 0; i < n; ++i)
        {
            int sz = deleted.size();
            for (int j = 0; j < sz; ++j)
            {
                if (i == deleted[j] && child[i] != 100)
                {
                    child[i] = 100;
                    child[arr[i]]--;
                    comp = false;
                }
                else if (arr[i] == deleted[j] && child[i] != 100)
                {
                    child[i] = 100;
                    comp = false;
                    deleted.emplace_back(i);
                }
            }
        }
    }

    int ans = 0;
    for (auto &c : child)
        if (c == 0)
            ans++;

    cout << ans << "\n";

    return 0;
}