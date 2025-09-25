#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        int m;
        cin >> m;
        priority_queue<int, vector<int>> Max_Heap;
        priority_queue<int, vector<int>, greater<int>> Min_Heap;

        cout << m / 2 + 1 << "\n";

        while (m--)
        {
            int num;
            cin >> num;

            if (Max_Heap.size() == Min_Heap.size())
                Max_Heap.push(num);
            else
                Min_Heap.push(num);

            if (!Min_Heap.empty() && Max_Heap.top() > Min_Heap.top())
            {
                Max_Heap.push(Min_Heap.top());
                Min_Heap.pop();
                Min_Heap.push(Max_Heap.top());
                Max_Heap.pop();
            }

            if ((Max_Heap.size() + Min_Heap.size()) % 2 == 1)
                cout << Max_Heap.top() << " ";
        }

        cout << "\n";
    }

    return 0;
}