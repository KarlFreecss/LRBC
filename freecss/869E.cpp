#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2505;
const int MAXM = 2505;

typedef unsigned long long ull;

ull flag[MAXN][MAXM];
ull tree[MAXN][MAXM];
int n, m, q;

void update(int x, int y, ull v){
    for (;x <= n; x += x & -x) {
        for (int c = y; c <= m; c += c & -c) {
            tree[x][c] ^= v;
        }
    }
}

ull getV(int x, int y){
    ull res = 0;
    for (;x; x -= x & -x) {
        for (int c = y; c; c -= c & -c) {
            res ^= tree[x][c];
        }
    }
    return res;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    srand(time(0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            flag[i][j] = rand() * rand();
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            flag[i][j] += flag[i-1][j-1] + flag[i-1][j] + flag[i][j-1];
        }
    }
    for (int i = 0; i < q; ++i) {
        int opt, r1, c1, r2, c2;
        scanf("%d%d%d%d%d", &opt, &r1, &c1, &r2, &c2);
        if (opt < 3){
            update(r1, c1, flag[r1][c1] + flag[r2][c2]);
            update(r1, c2 + 1, flag[r1][c1] + flag[r2][c2]);
            update(r2 + 1, c1, flag[r1][c1] + flag[r2][c2]);
            update(r2+1, c2+1, flag[r1][c1] + flag[r2][c2]);
        } else {
            ull a = getV(r1, c1);
            ull b = getV(r2, c2);
 //           cout << a << ' ' << b << endl;
            if (a == b) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
