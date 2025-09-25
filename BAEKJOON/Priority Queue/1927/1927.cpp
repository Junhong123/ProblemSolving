#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;

    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (q.empty())
                cout << "0\n";
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(num);
        }
    }

    return 0;
}