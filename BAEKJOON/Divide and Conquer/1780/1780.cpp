#include<bits/stdc++.h>

using namespace std;

int cnt[3] = {};

void run(vector<vector<int>>& v, int x, int y, int size){
    bool isP = true;

    for (int i = x; i < x + size; i++){
        for (int j = y; j < y + size; j++){
            if(v[x][y] != v[i][j]){
                isP = false;
                break;
            }
        }
        if(!isP)
            break;
    }

    if(isP){
        if(v[x][y] == -1)
            cnt[0]++;
        else if(v[x][y] == 0)
            cnt[1]++;
        else
            cnt[2]++;
    } else {
        int newSize = size / 3;
        run(v, x, y, newSize);
        run(v, x + newSize, y, newSize);
        run(v, x, y + newSize, newSize);
        run(v, x + newSize + newSize, y, newSize);
        run(v, x, y + newSize + newSize, newSize);
        run(v, x + newSize, y + newSize, newSize);
        run(v, x + newSize, y + newSize + newSize, newSize);
        run(v, x + newSize + newSize, y + newSize, newSize);
        run(v, x + newSize + newSize, y + newSize + newSize, newSize);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;

    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    run(v, 0, 0, n);

    for(auto val : cnt)
        cout << val << "\n";

    return 0;
}