#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n, -1);
    vector<int> numbers(1000001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        numbers[arr[i]]++;
    }

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && numbers[arr[st.top()]] < numbers[arr[i]])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (auto &val : ans)
        cout << val << " ";
    return 0;
}