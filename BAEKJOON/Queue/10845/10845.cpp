#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
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
            q.push(num);
        }
        else if (str == "front")
        {
            if (!q.empty())
                cout << q.front();
            else
                cout << "-1";
            cout << "\n";
        }
        else if (str == "size")
        {
            cout << q.size() << "\n";
        }
        else if (str == "empty")
        {
            if (q.empty())
                cout << 1;
            else
                cout << 0;
            cout << "\n";
        }
        else if (str == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (str == "back")
        {
            if (!q.empty())
                cout << q.back();
            else
                cout << -1;
            cout << "\n";
        }
    }
    return 0;
}