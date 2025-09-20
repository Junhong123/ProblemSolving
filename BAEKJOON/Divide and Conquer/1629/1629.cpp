#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll power(ll A, ll B, ll C){
    if(B == 1){
        return A % C;
    } else {

        ll cal = power(A, B / 2, C);
        ll val = cal * cal % C;

        if(B % 2 == 1){
            val = val * A % C;
        }

        return val;
    }
}

int main(){
    ll A, B, C;

    cin >> A >> B >> C;

    cout << power(A, B, C) << "\n";

    return 0;
}