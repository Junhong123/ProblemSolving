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
    vector<char> ans;
    stack<int> st;
    int cnt = 1;
    int next = 0;
    bool isP = true;
    while (next < n)
    {
        if (st.empty() || st.top() < arr[next])
        {
            st.push(cnt++);
            ans.emplace_back('+');
        }
        else if (!st.empty() && st.top() == arr[next])
        {
            st.pop();
            ans.emplace_back('-');
            next++;
        }
        else if (!st.empty() && st.top() > arr[next])
        {
            isP = false;
            break;
        }
    }

    if (isP)
        for (auto &val : ans)
            cout << val << "\n";
    else
        cout << "NO\n";

    return 0;
}