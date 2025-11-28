#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            int cnt = 1;
            int idx = st.top();
            st.pop();
            stack<int> tmp;
            while (!st.empty() && arr[idx] <= arr[st.top()])
            {
                cnt++;
                if (arr[idx] == arr[st.top()])
                {
                    tmp.push(st.top());
                    st.pop();
                    continue;
                }
                else
                {
                    break;
                }
            }

            while (!tmp.empty())
            {
                st.push(tmp.top());
                tmp.pop();
            }

            res += cnt;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int idx = st.top();
        st.pop();
        int cnt = 0;
        stack<int> tmp;
        while (!st.empty() && arr[idx] <= arr[st.top()])
        {
            cnt++;
            if (arr[idx] == arr[st.top()])
            {
                tmp.push(st.top());
                st.pop();
                continue;
            }
            else
            {
                break;
            }
        }

        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }

        res += cnt;
    }

    cout << res << "\n";

    return 0;
}