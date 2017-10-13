#include <bits/stdc++.h>

using namespace std;

int a[102][103];
int s[102][103];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            s[i][j] = a[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s[i][j] += s[i-1][j];
        }
    }

    int repleaceNum = 0;
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        int maxC = 0;
        int index = -1;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 1) {
                int _k = min(k, n - i);
                int C = s[i+_k - 1][j] - s[i][j] + 1;
                if (C > maxC) {
                    maxC = C;
                    index = i;
                }
            }
        }
        if (maxC > 0) {
            for (int i = 0; i < index; ++i) {
                if (a[i][j] == 1) count++;
            }
        }
        ans += maxC;
        repleaceNum += count;
    }
    cout << ans << ' ' << repleaceNum << endl;
    return 0;
}
