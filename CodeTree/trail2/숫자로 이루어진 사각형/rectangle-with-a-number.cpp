#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    int cnt = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << cnt << " ";
            cnt = ++cnt == 10 ? 1 : cnt;
        }
        cout << "\n";
    }
    return 0;
}