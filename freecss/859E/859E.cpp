#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;
const int MO = 1e9 + 7;

int f[MAXN * 2];
int s[MAXN * 2];
int c[MAXN * 2];
int mark[MAXN * 2];

int n;

int find(int x){
    if (x != f[x]) return f[x] = find(f[x]);
    return f[x];
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
        f[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        int fa = find(a);
        int fb = find(b);
        ++c[fa];
        if (a == b) {
            mark[fa] = 1;
        }
        if (fa == fb) continue;
        s[fa] += s[fb];
        c[fa] += c[fb];
        mark[fa] |= mark[fb];
        f[fb] = fa;
    }
    
    long long ans = 1;
    for (int i = 1; i <= 2*n; ++i) {
        int fa = find(i);
        if (mark[fa] == 1) continue;
        if (s[fa] == 1) continue;
        if (s[fa] == c[fa]) {
            ans *= 2;
            ans %= MO;
        } else {
            ans *= s[fa];
            ans %= MO;
        }
        s[fa] = 1;
    }
    cout << ans << endl;
    return 0;
}
