#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] > t) cnt++;
        else cnt = 0;
        res = max(res, cnt);
    }

    cout << res;
    
    return 0;
}