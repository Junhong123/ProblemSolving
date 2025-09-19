#include <bits/stdc++.h>
#include <span>

using namespace std;

void div(span<vector<int>> square, int* white, int* blue, int start, int size) {
    bool isPerfect = true;

    int first = square[0][start];

    for(auto row : square){
        auto col_span = span(row).subspan(start, size);
        for(int val : col_span){
            if(val != first){
                isPerfect = false;
                break;
            }
        }
        if(!isPerfect) break;
    }

    if(isPerfect){
        if(first == 0){
            *white += 1;
        }
        else{
            *blue += 1;
        }
    } else {
        span<vector<int>> newSquare1 = square.subspan(0, square.size() / 2);
        span<vector<int>> newSquare2 = square.subspan(square.size() / 2, square.size() / 2);

        for(int i = 0; i < 2; i++){
            div(newSquare1, white, blue, start + size / 2 * i, size / 2);
            div(newSquare2, white, blue, start + size / 2 * i, size / 2);
        }
    }
}

int main(){
    int n;
    int white = 0;
    int blue = 0;

    cin >> n;

    vector<vector<int>> square(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> square[i][j];
        }
    }
    
    div(square, &white, &blue, 0, n);

    cout << white << "\n" << blue << "\n";

    return 0;
}