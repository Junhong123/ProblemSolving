#include <bits/stdc++.h>

using namespace std;

void run (vector<vector<int>>& square, int x, int y, int size, bool last = false){
    bool isP = true;
    int first = square[x][y];

    for (int i = x; i < x + size; i++){
        for (int j = y; j < y + size; j++)
        {
            if(first != square[i][j])
                isP = false;
            if(!isP)
                break;
        }
        if(!isP)
            break;
    }

    if(isP){
        if(first == 1)
            cout << "1";
        else
            cout << "0";
    } else {
        cout << "(";
        int newSize = size / 2;
        run(square, x, y, newSize);
        run(square, x, y + newSize, newSize);
        run(square, x + newSize, y, newSize);
        run(square, x + newSize, y + newSize, newSize, true);
    }
    
    if(last)
        cout << ")";
}

int main(){
    int n;
    int x = 0;
    int y = 0;

    cin >> n;

    vector<vector<int>> square(n, vector<int> (n));

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        for (int j = 0; j < n; j++){
            square[i][j] = str[j] - 48;
        }
    }

    run(square, x, y, n);

    return 0;
}