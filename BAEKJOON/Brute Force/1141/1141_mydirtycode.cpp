#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tmp;
    int n;
    int sz = 0;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        bool is_empl = true;
        for (int j = 0; j < sz; ++j)
        {
            bool isC = true;
            for (int k = 0; k < arr[j].length(); ++k)
            {
                if (tmp.length() <= k)
                {
                    isC = false;
                    is_empl = false;
                    break;
                }
                if (arr[j][k] != tmp[k])
                {
                    isC = false;
                    break;
                }
            }
            if (isC)
            {
                arr[j] = tmp;
                is_empl = false;
                break;
            }
            if (!is_empl)
                break;
        }
        if (is_empl)
        {
            arr[sz++] = tmp;
        }
    }

    cout << sz;
    return 0;
}