#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll power(ll A, ll B, ll C){
    if(B == 0)
        return 1;
    if(B == 1)
        return A % C;

    ll cal = power(A, B / 2, C);
    ll val = cal * cal % C;
    if(B % 2 != 0)
        val = val * A % C;

    return val;
}

ll fac(ll num, ll C){
    ll res = 1;
    for (int i = 2; i <= num; i++){
        res = res * i % C;
    }
    return res;
}

int main(){
    ll n, k;
    const ll C = 1000000007;

    cin >> n >> k;

    // N! / K!(N-K)!
    ll A = fac(n, C);
    ll B = fac(k, C) * fac(n - k, C) % C;

    B = power(B, C - 2, C);

    ll res = A * B % C;

    cout << res << "\n";

    return 0;
}