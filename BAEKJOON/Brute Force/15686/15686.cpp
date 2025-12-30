#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;
    cin >> n >> m;
    vector<pair<int, int>> houses;
    vector<pair<int, int>> chickens;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (num == 1)
                houses.emplace_back(i, j);
            else if (num == 2)
                chickens.emplace_back(i, j);
        }
    }

    vector<int> selector(chickens.size(), 1);
    for (int i = 0; i < m; i++)
        selector[i] = 0;

    int min_city_dist = 2e9;

    do
    {
        int cur_city_dist = 0;
        for (const auto &h : houses)
        {
            int min_house_dist = 2e9;

            for (int i = 0; i < chickens.size(); i++)
            {
                if (selector[i] == 0)
                {
                    int dist = abs(h.first - chickens[i].first) + abs(h.second - chickens[i].second);
                    min_house_dist = min(min_house_dist, dist);
                }
            }
            cur_city_dist += min_house_dist;

            if (cur_city_dist > min_city_dist)
                break;
        }

        min_city_dist = min(min_city_dist, cur_city_dist);
    } while (next_permutation(selector.begin(), selector.end()));

    cout << min_city_dist << "\n";

    return 0;
}