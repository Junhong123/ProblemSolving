#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<pair<int, int>> st;

    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        int re = 1;
        while (!st.empty() && st.top().first < cur)
        {
            res += st.top().second;
            st.pop();
        }

        if (!st.empty())
        {
            if (st.top().first == cur)
            {
                res += st.top().second;
                re += st.top().second;
                st.pop();

                if (!st.empty())
                    res++;
            }
            else if (st.top().first > cur)
                res++;
        }

        st.push({cur, re});
    }

    cout << res << "\n";

    return 0;
}