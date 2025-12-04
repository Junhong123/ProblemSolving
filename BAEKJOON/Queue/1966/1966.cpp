#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        queue<int> q;
        vector<int> arr(n);
        vector<bool> pull(n, true);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            q.push(i);
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            bool check = true;
            for (int i = 0; i < n; i++)
            {
                if (pull[i] == true && arr[cur] < arr[i])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                pull[cur] = false;
                cnt++;
                if (cur == m)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else
            {
                q.push(cur);
            }
        }
    }
    return 0;
}