#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, num;
    char c;
    cin >> T;
    while (T--)
    {
        cin >> n;
        priority_queue<int> pq2;
        priority_queue<int, vector<int>, greater<int>> pq1;
        map<int, int> pmp;
        map<int, int> mmp;
        while (n--)
        {
            cin >> c >> num;
            if (c == 'I')
            {
                pq1.push(num);
                pq2.push(num);
                if (num >= 0)
                    pmp[num]++;
                else
                    mmp[-num]++;
            }
            else
            {
                bool cng = false;
                if (num == 1)
                {
                    while (!cng && !pq2.empty())
                    {
                        int cur = pq2.top();
                        pq2.pop();
                        if (cur >= 0)
                        {
                            if (pmp[cur] != 0)
                            {
                                pmp[cur]--;
                                cng = true;
                            }
                        }
                        else
                        {
                            if (mmp[-cur] != 0)
                            {
                                mmp[-cur]--;
                                cng = true;
                            }
                        }
                    }
                }
                else
                {
                    while (!cng && !pq1.empty())
                    {
                        int cur = pq1.top();
                        pq1.pop();
                        if (cur >= 0)
                        {
                            if (pmp[cur] != 0)
                            {
                                pmp[cur]--;
                                cng = true;
                            }
                        }
                        else
                        {
                            if (mmp[-cur] != 0)
                            {
                                mmp[-cur]--;
                                cng = true;
                            }
                        }
                    }
                }
            }
        }

        bool fin1 = false;
        bool fin2 = false;

        while (!fin1 || !fin2)
        {
            if (!fin1)
            {
                if (pq1.empty())
                    fin1 = true;
                else
                {
                    int cur = pq1.top();
                    if (cur >= 0)
                    {
                        if (pmp[cur] != 0)
                            fin1 = true;
                        else
                            pq1.pop();
                    }
                    else
                    {
                        if (mmp[-cur] != 0)
                            fin1 = true;
                        else
                            pq1.pop();
                    }
                }
            }
            if (!fin2)
            {
                if (pq2.empty())
                    fin2 = true;
                else
                {
                    int cur = pq2.top();
                    if (cur >= 0)
                    {
                        if (pmp[cur] != 0)
                            fin2 = true;
                        else
                            pq2.pop();
                    }
                    else
                    {
                        if (mmp[-cur] != 0)
                            fin2 = true;
                        else
                            pq2.pop();
                    }
                }
            }
        }

        if (pq1.empty() || pq2.empty())
        {
            cout << "EMPTY";
        }
        else
        {
            cout << pq2.top() << " " << pq1.top();
        }
        cout << "\n";
    }
    return 0;
}