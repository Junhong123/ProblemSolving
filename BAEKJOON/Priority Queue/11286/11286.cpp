#include <bits/stdc++.h>

using namespace std;

struct Compare
{
    bool operator()(int &a, int &b)
    {
        if (abs(a) != abs(b))
        {
            return abs(a) > abs(b);
        }
        return a > b;
    }
};

int main()
{
    priority_queue<int, vector<int>, Compare> pq;
    int n;
    cin >> n;

    int num;
    while (n--)
    {
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
                cout << "0\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}