#include <bits/stdc++.h>

#define debug() cout << __FILE__ << "_" << __LINE__ << ' '

using namespace std;

int main(){
    int n;
    cin >> n;
    int m = (1 << n);
    vector<vector<double>> pro(m), ans(n), f(n);
    for (int i = 0; i < n; ++i) {
        ans[i].resize(m);
        f[i].resize(m);
    }
    for (int i = 0; i < m; ++i) {
        pro[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> pro[i][j];
            pro[i][j] /= 100;
        }
    }
    for (int j = 0; j < m; ++j) {
        f[0][j] = pro[j][j^1];
        ans[0][j] = f[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int oppG = j & (~((1<<i)-1)) ^ (1<<i);
            for (int k = 0; k < (1<<i); ++k) {
                int opp = oppG + k;
                f[i][j] += f[i-1][j] * f[i-1][opp] * pro[j][opp];
                ans[i][j] = max(ans[i][j], ans[i-1][opp]);
            }
            ans[i][j] += f[i][j] * (1 << i) + ans[i-1][j];
        }
    }
    double ANS = 0;
    for (int i = 0; i < m; ++i) {
        ANS = max(ANS, ans[n-1][i]);
    }
    printf("%.15lf", ANS);

    return 0;
}
