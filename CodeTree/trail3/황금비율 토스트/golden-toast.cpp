#include <iostream>
#include <list>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    list<char> l;
    char tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        l.push_back(tmp);
    }
    list<char>::iterator it = l.end();
    while(m--) {
        cin >> tmp;
        if(tmp == 'L') {
            if(it != l.begin()) it--;
        } else if (tmp == 'R') {
            if(it != l.end()) it++;
        } else if (tmp == 'D') {
            if(it != l.end()) {
                it = l.erase(it);
            }
        } else if (tmp == 'P') {
            cin >> tmp;
            l.insert(it, tmp);
        }
    }
    for(auto &v : l) cout << v;
    cout << "\n";
    return 0;
}