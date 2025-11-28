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
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int height = arr[st.top()];
            st.pop();

            int width = i;

            if (!st.empty())
            {
                width = i - st.top() - 1;
            }

            mx = max(mx, height * width);
        }

        st.push(i);
    }

    while (!st.empty())
    {
        int height = arr[st.top()];
        st.pop();

        int width = n;
        if (!st.empty())
        {
            width = n - st.top() - 1;
        }

        mx = max(mx, height * width);
    }

    cout << mx << "\n";

    return 0;
}