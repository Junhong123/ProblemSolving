#include <bits/stdc++.h>

using namespace std;

struct Compare
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first != p2.first)
            return p1.first > p2.first;
        else
            return p1.second < p2.second;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    priority_queue<int, vector<int>, greater<int>> bag;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        pq.push(tmp);
    }

    for (int i = 0; i < k; i++)
    {
        int weight;
        cin >> weight;
        bag.push(weight);
    }

    priority_queue<int, vector<int>> res;
    long long ans = 0;

    for (int i = 0; i < k; i++)
    {
        int weight = bag.top();
        bag.pop();
        while (!pq.empty() && pq.top().first <= weight)
        {
            int value = pq.top().second;
            res.push(value);
            pq.pop();
        }
        if (!res.empty())
        {
            ans += res.top();
            res.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}