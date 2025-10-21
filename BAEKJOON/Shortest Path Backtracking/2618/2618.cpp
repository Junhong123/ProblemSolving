#include <bits/stdc++.h>

using namespace std;

int n, w;
vector<pair<int, int>> arr;
vector<vector<int>> dp;
vector<vector<int>> path;

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int idx1, int idx2)
{
    int nidx = max(idx1, idx2) + 1;
    if (nidx >= arr.size())
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];
    int dist1, dist2;
    dist1 = dist(arr[idx1].first, arr[idx1].second, arr[nidx].first, arr[nidx].second);
    if (idx2 == 0)
        dist2 = dist(n, n, arr[nidx].first, arr[nidx].second);
    else
        dist2 = dist(arr[idx2].first, arr[idx2].second, arr[nidx].first, arr[nidx].second);

    int cost1 = solve(nidx, idx2);
    int cost2 = solve(idx1, nidx);

    if (dist1 + cost1 < dist2 + cost2)
    {
        path[idx1][idx2] = 1;
        dp[idx1][idx2] = dist1 + cost1;
    }
    else
    {
        path[idx1][idx2] = 2;
        dp[idx1][idx2] = dist2 + cost2;
    }

    return dp[idx1][idx2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    arr = vector<pair<int, int>>(w + 1);
    dp = vector<vector<int>>(w + 1, vector<int>(w + 1, -1));
    path = vector<vector<int>>(w + 1, vector<int>(w + 1));

    arr[0] = {1, 1};
    for (int i = 1; i <= w; i++)
        cin >> arr[i].first >> arr[i].second;

    cout << solve(0, 0) << "\n";

    int idx1 = 0;
    int idx2 = 0;

    for (int i = 0; i < w; i++)
    {
        if (path[idx1][idx2] == 1)
        {
            cout << "1\n";
            idx1 = max(idx1, idx2) + 1;
        }
        else
        {
            cout << "2\n";
            idx2 = max(idx1, idx2) + 1;
        }
    }

    return 0;
}