#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상을 위한 설정 (시간 초과 방지)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n; 

    stack<int> s;
    string cmd;

    while (n--) {
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        } 
        else if (cmd == "pop") {
            if (s.empty()) {
                cout << -1 << "\n"; // 스택이 비어있을 경우 예외 처리
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } 
        else if (cmd == "size") {
            cout << s.size() << "\n";
        } 
        else if (cmd == "empty") {
            cout << (s.empty() ? 1 : 0) << "\n";
        } 
        else if (cmd == "top") {
            if (s.empty()) {
                cout << -1 << "\n"; // 스택이 비어있을 경우 예외 처리
            } else {
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}