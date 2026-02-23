#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    cin >> n;
    vector<int> selected(n, 0);
    for (int order = 1; order <= n; ++order)
    {
        cin >> num;
        for (int i = 0; i < n; ++i)
        {
            if (num == 0 && !selected[i])
            {
                selected[i] = order;
                break;
            }
            if (!selected[i])
                num--;
        }
    }

    for (auto &ans : selected)
        cout << ans << " ";
    cout << "\n";

    return 0;
}