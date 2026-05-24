#include <iostream>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    int arr[10000];
    int N, n;
    int sz = 0;
    string str;
    cin >> N;
    while(N--) {
        cin >> str;
        if(str == "push_back") {
            cin >> n;
            arr[sz++] = n;
        } else if (str == "pop_back") sz--;
        else if (str == "size") cout << sz << "\n";
        else {
            cin >> n;
            cout << arr[n - 1] << "\n";
        }
    }
    return 0;
}