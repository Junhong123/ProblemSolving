#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> requests(n);
    int max_request = 0;
    long long total_request_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> requests[i];
        max_request = max(max_request, requests[i]);
        total_request_sum += requests[i];
    }

    long long m;
    cin >> m;

    if (total_request_sum <= m)
    {
        cout << max_request << "\n";
        return 0;
    }

    int left = 0;
    int right = max_request;
    int answer = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long current_budget_sum = 0;

        for (int req : requests)
        {
            current_budget_sum += min(req, mid);
        }

        if (current_budget_sum <= m)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}