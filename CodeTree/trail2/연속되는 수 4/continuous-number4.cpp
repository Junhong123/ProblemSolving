#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int res = 1;
    int cnt = 1;

    for(int i = 1; i < n; ++i) {
        if(arr[i - 1] >= arr[i]) cnt = 1;
        else cnt++;
        res = max(res, cnt);
    }

    cout << res;

    return 0;
}