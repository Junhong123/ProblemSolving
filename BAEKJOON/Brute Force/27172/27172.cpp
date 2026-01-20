#include <bits/stdc++.h>

using namespace std;

int pos[1000001];
int cards[100001];
int score[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cur, n, num;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        pos[num] = i;
        cards[i] = num;
        score[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        cur = cards[i];
        for (int j = cur * 2; j <= 1000000; j += cur)
        {
            if (pos[j] != 0)
            {
                score[i]++;
                score[pos[j]]--;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << score[i] << " ";
    cout << "\n";

    return 0;
}