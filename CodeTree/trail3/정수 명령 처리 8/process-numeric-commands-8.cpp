#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    list<int> l;
    int N, x;
    string str;
    cin >> N;
    while(N--) {
        cin >> str;
        if(str == "push_front") {
            cin >> x;
            l.push_front(x);
        } else if (str == "push_back") {
            cin >> x;
            l.push_back(x);
        } else if (str == "pop_front") {
            cout << l.front() << "\n";
            l.pop_front();
        } else if (str == "pop_back") {
            cout << l.back() << "\n";
            l.pop_back();
        } else if (str == "size") {
            cout << l.size() << "\n";
        } else if (str == "empty") {
            if(l.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (str == "front") cout << l.front() << "\n";
        else if (str == "back") cout << l.back() << "\n";
    }
    return 0;
}