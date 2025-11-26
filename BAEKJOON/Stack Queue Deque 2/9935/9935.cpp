#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string boom;
    string str;
    int cnt = 0;
    cin >> str >> boom;
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        st.push(str[i]);
        if (st.top() == boom[0])
        {
            cnt = 1;
        }
        else if (st.top() == boom[cnt])
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        if (cnt == boom.size())
        {
            for (int i = 0; i < cnt; i++)
                st.pop();
            cnt = 0;
            stack<char> tmp;
            for (int i = 0; i < boom.size() - 1; i++)
            {
                if (!st.empty())
                {
                    tmp.push(st.top());
                    st.pop();
                }
            }
            for (int i = 0; i < boom.size() - 1; i++)
            {
                if (!tmp.empty())
                {
                    st.push(tmp.top());
                    tmp.pop();
                    if (st.top() == boom[0])
                    {
                        cnt = 1;
                    }
                    else if (st.top() == boom[cnt])
                    {
                        cnt++;
                    }
                    else
                    {
                        cnt = 0;
                    }
                }
            }
        }
    }

    if (st.empty())
    {
        cout << "FRULA";
    }
    else
    {
        vector<char> tmp;
        while (!st.empty())
        {
            tmp.emplace_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        for (auto ans : tmp)
            cout << ans;
    }

    cout << "\n";
    return 0;
}