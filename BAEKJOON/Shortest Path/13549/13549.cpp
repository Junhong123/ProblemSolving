#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> visited(MAX, MAX);

    deque<int> dq;

    dq.push_front(n);
    visited[n] = 0;

    while (!dq.empty())
    {
        int cur_node = dq.front();
        dq.pop_front();

        int next_node = cur_node * 2;
        if (next_node < MAX && next_node <= k * 2 && visited[next_node] > visited[cur_node])
        {
            dq.push_front(next_node);
            visited[next_node] = visited[cur_node];
        }

        next_node = cur_node + 1;
        if (next_node < MAX && visited[next_node] > visited[cur_node] + 1)
        {
            visited[next_node] = visited[cur_node] + 1;
            dq.push_back(next_node);
        }

        next_node = cur_node - 1;
        if (next_node >= 0 && visited[next_node] > visited[cur_node] + 1)
        {
            visited[next_node] = visited[cur_node] + 1;
            dq.push_back(next_node);
        }
    }

    cout << visited[k] << "\n";

    return 0;
}