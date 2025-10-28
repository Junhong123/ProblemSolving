#include <bits/stdc++.h>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> in_idx;

void find_preorder(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end)
        return;

    int root = postorder[post_end];
    cout << root << " ";

    int root_idx_in = in_idx[root];
    int left_size = root_idx_in - in_start;

    find_preorder(in_start, root_idx_in - 1, post_start, post_start + left_size - 1);
    find_preorder(root_idx_in + 1, in_end, post_start + left_size, post_end - 1);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    inorder.resize(n);
    postorder.resize(n);
    in_idx.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        in_idx[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    find_preorder(0, n - 1, 0, n - 1);
    cout << "\n";

    return 0;
}