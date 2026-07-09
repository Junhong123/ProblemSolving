#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Please write your code here.
    stack<int> st;
    string str;
    cin >> str;

    int i = 0;
    for(; i < str.length(); ++i) {
        if(str[i] == '(') st.push(1);
        else {
            if(st.empty()) 
                break;
            else 
                st.pop();
        }
    }

    if(i != str.length() || !st.empty()) cout << "No";
    else cout << "Yes";
    return 0;
}