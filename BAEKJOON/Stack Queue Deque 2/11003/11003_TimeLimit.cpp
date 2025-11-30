#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, cur, front;
    cin >> n >> l;
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        q.push(cur);
        mp[cur]++;
        pq.push(cur);
        if (q.size() > l)
        {
            front = q.front();
            q.pop();
            mp[front]--;
        }
        while (!pq.empty() && mp[pq.top()] == 0)
        {
            pq.pop();
        }
        cout << pq.top() << " ";
    }
    return 0;
}