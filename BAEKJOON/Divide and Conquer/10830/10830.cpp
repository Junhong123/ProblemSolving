#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, int n, int m, int r)
{
    vector<vector<int>> res(n, vector<int>(r, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < m; k++)
            {
                res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            res[i][j] = res[i][j] % 1000;
        }
    }

    return res;
}

vector<vector<int>> power(vector<vector<int>> &matrix, long long b)
{
    int size = matrix.size();
    if (b == 1)
    {
        return matrix;
    }

    vector<vector<int>> half = power(matrix, b / 2);

    vector<vector<int>> res = multiply(half, half, size, size, size);

    if (b % 2 == 1)
        res = multiply(res, matrix, size, size, size);

    return res;
}

int main()
{
    int n;
    long long b;
    cin >> n >> b;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            matrix[i][j] %= 1000;
        }
    }

    for (auto arr : power(matrix, b))
    {
        for (auto val : arr)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}