#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;

        int num;
        if (str == "push")
        {
            cin >> num;
            st.push(num);
        }
        else if (str == "top")
        {
            if (!st.empty())
                cout << st.top();
            else
                cout << "-1";
            cout << "\n";
        }
        else if (str == "size")
        {
            cout << st.size() << "\n";
        }
        else if (str == "empty")
        {
            if (st.empty())
                cout << 1;
            else
                cout << 0;
            cout << "\n";
        }
        else if (str == "pop")
        {
            if (!st.empty())
            {
                cout << st.top() << "\n";
                st.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}