#include <bits/stdc++.h>

using namespace std;

map<int, int> p;
map<int, int> f;

int mex(int x){
    if (f.count(x)) return f[x];
    set<int> S;
    for (int i = 1; (1 << i) <= x; ++i) {
        int y = (x >> i) | (x & ((1 << i) - 1));
        S.insert(mex(y));
    }
    for (int i = 0; i < x; ++i) {
        if (S.find(i) == S.end()) {
            f[x] = i;
            //cout << __LINE__ << ' ' << x << ' ' << i << endl;
            return i;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        for (int i = 2; i * i <= x; ++i) {
            if (x % i) continue;
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            p[i] |= (1 << cnt);
        }
        if (x != 1) p[x] |= 2;
    }
    int ans = 0;
    f[1] = 0;
    for (auto x : p) {
        ans ^= mex(x.second);
        //cout << x.first << ' ' << x.second << ' ' << ans << endl;
    }
    if (!ans) puts("Arpa");
    else puts("Mojtaba");
    return 0;
}
