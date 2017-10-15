#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0x7fffffff;
    for (int i = 1; i * i <= n; ++i) {
        int d = i;
        int l = n / i;
        int k = n % i;
        ans = min(ans, d * 2 + l * 2 + (k?2:0));
    }
    printf("%d\n", ans);
    return 0;
}
