#include <bits/stdc++.h>

using namespace std;

int getPriority(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> st;
    string str;
    cin >> str;

    string res = "";

    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];
        if (cur >= 'A' && cur <= 'Z')
            res += cur;
        else if (cur == '(')
            st.push(cur);
        else if (cur == ')')
        {
            char c = st.top();
            while (c != '(')
            {
                st.pop();
                res += c;
                c = st.top();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && getPriority(st.top()) >= getPriority(cur))
            {
                res += st.top();
                st.pop();
            }

            st.push(cur);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    cout << res;

    return 0;
}