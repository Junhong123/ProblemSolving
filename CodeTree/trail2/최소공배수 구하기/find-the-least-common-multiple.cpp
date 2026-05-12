#include <iostream>
using namespace std;

int solve(int a, int b) {
    int origin_a = a;
    int origin_b = b;
    while(true) {
        if(a == b) return a;
        if(a < b) a += origin_a;
        else b += origin_b;
    }
}

int main() {
    // Please write your code here.
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}