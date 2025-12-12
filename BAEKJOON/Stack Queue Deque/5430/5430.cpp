#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, fcnt, bcnt;
    bool R;
    string str1, str2;
    cin >> T;
    while (T--)
    {
        cin >> str1 >> n >> str2;
        fcnt = 0;
        bcnt = 0;
        R = false;
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] == 'R')
                R = !R;
            else
            {
                if (R)
                    bcnt++;
                else
                    fcnt++;
            }
        }
        if (bcnt + fcnt > n)
        {
            cout << "error\n";
            continue;
        }
        string tmp = "";
        deque<int> dq;
        for (int i = 0; i < str2.size(); i++)
        {
            if (isdigit(str2[i]))
            {
                tmp += str2[i];
            }
            else
            {
                if (!tmp.empty())
                {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }
        while (bcnt--)
            dq.pop_back();
        while (fcnt--)
            dq.pop_front();
        cout << "[";
        if (R)
        {
            while (!dq.empty())
            {
                cout << dq.back();
                dq.pop_back();
                if (!dq.empty())
                    cout << ",";
            }
        }
        else
        {
            while (!dq.empty())
            {
                cout << dq.front();
                dq.pop_front();
                if (!dq.empty())
                    cout << ",";
            }
        }
        cout << "]\n";
    }
    return 0;
}