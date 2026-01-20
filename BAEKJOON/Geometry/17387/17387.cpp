#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long long x, y;
};

int CCW(Point p1, Point p2, Point p3)
{
    long long temp = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
                     (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (temp > 0)
        return 1;
    else if (temp < 0)
        return -1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    int abc = CCW(A, B, C);
    int abd = CCW(A, B, D);
    int cda = CCW(C, D, A);
    int cdb = CCW(C, D, B);

    if (abc * abd == 0 && cda * cdb == 0)
    {
        if (make_pair(A.x, A.y) > make_pair(B.x, B.y))
            swap(A, B);
        if (make_pair(C.x, C.y) > make_pair(D.x, D.y))
            swap(C, D);

        if (make_pair(A.x, A.y) <= make_pair(D.x, D.y) && make_pair(C.x, C.y) <= make_pair(B.x, B.y))
            cout << "1\n";
        else
            cout << "0\n";
    }

    else if (abc * abd <= 0 && cda * cdb <= 0)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}