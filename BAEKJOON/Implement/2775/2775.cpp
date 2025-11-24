#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int k, n;
        cin >> k >> n;
        vector<vector<int>> arr(k + 1, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            arr[0][i] = i + 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k <= j; k++)
                    arr[i][j] += arr[i - 1][k];

        cout << arr[k][n - 1] << "\n";
    }

    return 0;
}