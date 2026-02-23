#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> arr;

int main()
{
    cin >> N;
    arr.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    return 0;
}