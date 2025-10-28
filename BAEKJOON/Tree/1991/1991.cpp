#include <bits/stdc++.h>

using namespace std;

map<char, pair<char, char>> tree;

void preorder(char node)
{
    cout << node;
    if (tree[node].first != '.')
        preorder(tree[node].first);
    if (tree[node].second != '.')
        preorder(tree[node].second);
}

void inorder(char node)
{
    if (tree[node].first != '.')
        inorder(tree[node].first);
    cout << node;
    if (tree[node].second != '.')
        inorder(tree[node].second);
}

void postorder(char node)
{
    if (tree[node].first != '.')
        postorder(tree[node].first);
    if (tree[node].second != '.')
        postorder(tree[node].second);
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        char parent, left, right;
        cin >> parent >> left >> right;
        tree[parent] = {left, right};
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";

    return 0;
}