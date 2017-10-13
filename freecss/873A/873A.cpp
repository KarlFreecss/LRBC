#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, k;
    scanf("%d%d%d", &n, &k, &x);
    int a, ans = k * x;
    for (int i = 0; i < n-k; ++i) {
        scanf("%d", &a);
        ans += a;
    }
    printf("%d\n", ans);
    return 0;
}
