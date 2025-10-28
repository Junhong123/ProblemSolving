#include <bits/stdc++.h>

using namespace std;

vector<int> preorder;

void find_postorder(int start, int end)
{
    if (start > end)
    {
        return;
    }

    int right_idx = -1;
    for (int i = start + 1; i <= end; i++)
    {
        if (preorder[i] > preorder[start])
        {
            right_idx = i;
            break;
        }
    }

    if (right_idx != -1)
        find_postorder(start + 1, right_idx - 1);
    else
        find_postorder(start + 1, end);

    if (right_idx != -1)
        find_postorder(right_idx, end);

    cout << preorder[start] << "\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    while (cin >> num)
    {
        preorder.emplace_back(num);
    }

    find_postorder(0, preorder.size() - 1);

    return 0;
}