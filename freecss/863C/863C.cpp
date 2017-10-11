#include <bits/stdc++.h>

using namespace std;

int matrixA[4][4];
int matrixB[4][4];

int simulate(long long & a, long long & b){
    int res = 0;
    if (a == 3 && b == 1) res = -1;
    else if (a == 1 && b == 3) res = 1;
    else {
        if (a > b) res = 1;
        else if (a < b) res = -1;
    }
    long long lastA = a, lastB = b;
    a = matrixA[lastA][lastB];
    b = matrixB[lastA][lastB];
    return res;
}

set<pair<int, int>> S;

int main(){
    long long k, a, b;
    cin >> k >> a >> b;
    for (int i = 1; i <= 3; ++i){
        for (int j = 1; j <= 3; ++j) {
            cin >> matrixA[i][j];
        }
    }
    for (int i = 1; i <= 3; ++i){
        for (int j = 1; j <= 3; ++j) {
            cin >> matrixB[i][j];
        }
    }
    long long scoreA = 0, scoreB = 0;
    long long times = 0;
    while (1) {
        if (S.find(make_pair(a, b)) != S.end()) break;
        S.insert(make_pair(a, b));
        int res = simulate(a, b);
        if (res > 0) scoreA++;
        else if (res < 0) scoreB++;
        if (--k == 0) {
            cout << scoreA << ' ' << scoreB << endl;
            return 0;
        }
    }
    long long sumA = 0;
    long long sumB = 0;
    sumA = scoreA;
    sumB = scoreB;

    S.clear();
    scoreA = 0;
    scoreB = 0;
    times = 0;
    while (1) {
        if (S.find(make_pair(a, b)) != S.end()) break;
        S.insert(make_pair(a, b));
        int res = simulate(a, b);
        ++times;
        if (res > 0) scoreA++;
        else if (res < 0) scoreB++;
    }

    long long circle = k / times;
    sumA += scoreA * circle;
    sumB += scoreB * circle;
    k = k - times * circle;
    while (k--){
        int res = simulate(a, b);
        if (res > 0) sumA++;
        else if (res < 0) sumB++;
    }
    cout << sumA << ' ' << sumB << endl;
    return 0;
}
