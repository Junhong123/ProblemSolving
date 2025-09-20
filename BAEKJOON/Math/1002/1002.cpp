#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int res = 0;

    cin >> n;

    while(n--){
        vector<int> x(2), y(2), r(2);
        cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

        int dist = pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2);
        vector<int> dist_r(2);
        dist_r[0] = pow(r[0] + r[1], 2);
        dist_r[1] = pow(r[0] - r[1], 2);

        if(dist == 0) {
            if(r[0] == r[1])
                cout << "-1\n";
            else
                cout << "0\n";
            continue;
        }
        
        if(dist > dist_r[0] || dist < dist_r[1])
            cout << "0\n";
        else if(dist == dist_r[0] || dist == dist_r[1])
            cout << "1\n";
        else
            cout << "2\n";
    }

    return 0;
}