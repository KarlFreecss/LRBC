//#reason : I don't know how to do!
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int MO = 1e9+7;

vector<int> g[MAXN];
long long f[MAXN][3][11];

int n, m, k, x;

void dfs(int u, int fa){
    long long tmp[2][3][11] = {0};
    tmp[0][0][0] = k - 1;
    tmp[0][1][1] = 1;
    tmp[0][2][0] = m - k;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        memset(tmp[1], 0, 3*11*sizeof(long long));
        for (int k = x; k >= 0; --k) {
            for (int j = 0; j <= k; ++j) {
                tmp[1][0][k] += tmp[0][0][j] * ((f[v][0][k-j] + f[v][2][k-j] + f[v][1][k-j]) % MO);
                tmp[1][0][k] %= MO;

                tmp[1][1][k] += tmp[0][1][j] * (f[v][0][k-j]);
                tmp[1][1][k] %= MO;

                tmp[1][2][k] += tmp[0][2][j] * ((f[v][0][k-j] + f[v][2][k-j]) % MO);
                tmp[1][2][k] %= MO;
            }
        }
        memcpy(tmp[0], tmp[1], 3*11*sizeof(long long));
    }
    for (int i = 0; i <= x; ++i) {
        for (int k = 0; k < 3; ++k) {
            f[u][k][i] = tmp[0][k][i];
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d%d", &k, &x);
    dfs(1, 1);
    long long res = 0;
    for (int i = 0; i <= x; ++i) {
        for (int k = 0; k < 3; ++k) {
            res = (res + f[1][k][i]) % MO;
        }
    }
    cout << res << endl;
    return 0;
}
