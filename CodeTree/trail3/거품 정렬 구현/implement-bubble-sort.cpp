#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; ++i) cin >> arr[i];
    while(true) {
        bool sorted = true;
        for(int i = 0; i < N - 1; ++i) {
            if(arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = false;
            }
        }
        if(sorted) break;
    }
    for(auto &v : arr) cout << v << " ";
    return 0;
}