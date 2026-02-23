#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();

    int min_l = n + m;

    for (int offset = -m + 1; offset < n; ++offset)
    {
        bool cn = true;

        for (int k = 0; k < m; ++k)
        {
            int j = offset + k;

            if (j >= 0 && j < n)
            {
                if (str1[j] == '2' && str2[k] == '2')
                {
                    cn = false;
                    break;
                }
            }
        }

        if (cn)
        {
            int left = min(0, offset);
            int right = max(n - 1, offset + m - 1);
            int cur = right - left + 1;
            min_l = min(min_l, cur);
        }
    }

    cout << min_l << "\n";

    return 0;
}