#include <iostream>
using namespace std;

int solve(int a, int b) {
    int r = a % b;
    if(r == 0) return b;
    else return solve(b, r);
}

int main() {
    // Please write your code here.
    int a; int b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}