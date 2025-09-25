#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    int cnt = n * n;

    while (cnt--)
    {
        int num;
        cin >> num;

        if (pq.size() < n)
        {
            pq.push(num);
        }
        else
        {
            if (pq.top() < num)
            {
                pq.pop();
                pq.push(num);
            }
        }
    }

    cout << pq.top() << "\n";

    return 0;
}