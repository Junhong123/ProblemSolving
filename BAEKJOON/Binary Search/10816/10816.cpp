#include <iostream>
#include <map>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int tmp;

    cin >> N;

    map<int, int> m;

    while (N--)
    {
        cin >> tmp;
        if (m.find(tmp) != m.end())
            m[tmp]++;
        else
            m.insert({tmp, 1});
    }

    cin >> M;

    while (M--)
    {
        cin >> tmp;
        if (m.find(tmp) != m.end())
            cout << m[tmp] << " ";
        else
            cout << "0 ";
    }

    return 0;
}