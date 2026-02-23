#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    double L, W, H;
    cin >> N >> L >> W >> H;

    double low = 0.0;
    double high = max({L, W, H});
    double ans = 0.0;

    for (int i = 0; i < 100; ++i)
    {
        double mid = low + (high - low) / 2.0;

        long long cL = (long long)(L / mid);
        long long cW = (long long)(W / mid);
        long long cH = (long long)(H / mid);

        if (cL == 0 || cW == 0 || cH == 0)
        {
            high = mid;
            continue;
        }

        long double tot = (long double)cL * (long double)cW * (long double)cH;

        if (tot >= (long double)N)
        {
            ans = mid;
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << fixed << setprecision(15) << ans << "\n";

    return 0;
}