#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans, cnt;
    bool isl = true;
    stack<char> st;
    string str;
    cin >> str;
    ans = 0;
    cnt = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
            isl = true;
            cnt++;
        }
        else if (str[i] == ')')
        {
            st.pop();
            if (isl)
            {
                isl = false;
                ans += --cnt;
            }
            else
            {
                cnt--;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}