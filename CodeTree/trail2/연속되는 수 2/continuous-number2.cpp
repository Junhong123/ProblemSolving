#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; ++i) cin >> arr[i];
    int res = 1;
    int cnt = 1;
    for(int i = 1; i < N; ++i) {
        if(arr[i] == arr[i-1]) cnt++;
        else cnt = 1;
        res = max(res, cnt);
    }

    cout << res;

    return 0;
}