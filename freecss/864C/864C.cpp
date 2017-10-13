#include<bits/stdc++.h>

using namespace std;

int a, b, f, k;

int go(int a, int rb, int f, int k){
    if (k == 0) return 0;
    if (b < f) return -9999999;
    if (k == 1) {
        if (rb >= a) return 0;
        else if (rb >= f && b >= (a-f)) return 1;
        else return -9999999;
    }
    if (rb >= 2 * a - f) {
        return go(a, rb - a, a - f, k - 1);
    } else return go(a, b - (a-f), a - f, k - 1) + 1;
}

int main(){
    cin >> a >> b >> f >> k;

    cout << max(-1, go(a, b, f, k)) << endl;

    return 0;
}
