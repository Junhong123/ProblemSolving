#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    B += A * 60;
    D += C * 60;

    cout << D - B;
    
    return 0;
}