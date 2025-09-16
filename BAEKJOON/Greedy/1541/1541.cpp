#include <bits/stdc++.h>

using namespace std;

int main(){
    int n[50];
    char sign[50];
    int cnt = 0;
    int res = 0;
    int sum = 0;

    cin >> n[0];

    while (!cin.eof()){
        cnt++;
        cin >> sign[cnt] >> n[cnt];
    }

    for(int i = cnt - 1; i > 0; i--){

        sum += n[i];

        if (sign[i] == '-'){
            res -= sum;
            sum = 0;
        }
    }

    sum += n[0];
    res += sum;

    cout << res << endl;

    return 0;
}