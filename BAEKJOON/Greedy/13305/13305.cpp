#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    unsigned long long res = 0;
    unsigned long long sum = 0;
    unsigned long long min;

    cin >> n;

    int* length = new int[n-1];
    int* cost = new int[n];

    for(int i = 0; i < n-1; i++)
        cin >> length[i];

    for(int i = 0; i < n; i++)
        cin >> cost[i];

    min = cost[0];
    for(int i = 0; i < n-1; i++) {
        if(cost[i] < min) {
            res += sum;
            sum = 0;
            min = cost[i];
        }
        sum += min * length[i];
    }

    res += sum;

    cout << res << "\n";

    return 0;
}