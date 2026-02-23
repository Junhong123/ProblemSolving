#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num, ans;
    cin >> N;
    priority_queue<int, vector<int>, less<int>> pq_less;       // 큰거부터
    priority_queue<int, vector<int>, greater<int>> pq_greater; // 작은거부터

    while (N--)
    {
        cin >> num;
        if (pq_less.size() > pq_greater.size())
            pq_greater.push(num);
        else
            pq_less.push(num);

        if (!pq_less.empty() && !pq_greater.empty())
            if (pq_less.top() > pq_greater.top())
            {
                int tmp = pq_less.top();
                pq_less.pop();
                pq_less.push(pq_greater.top());
                pq_greater.pop();
                pq_greater.push(tmp);
            }

        cout << pq_less.top() << "\n";
    }

    return 0;
}