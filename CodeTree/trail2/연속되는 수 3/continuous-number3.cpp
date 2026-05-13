#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int arr[1000];
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];

    int res = 1;
    int cnt = 1;
    bool ispl;
    if(arr[0] > 0) ispl = true;
    else ispl = false;

    for(int i = 1; i < N; ++i) {
        if((ispl && arr[i] > 0) || (!ispl && arr[i] < 0)) cnt++;
        else {
            cnt = 1;
            ispl = !ispl;
        }
        res = max(cnt, res);
    }

    cout << res;

    return 0;
}