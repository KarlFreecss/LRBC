#include<bits/stdc++.h>

using namespace std;

priority_queue<int> que;

const int MAXN = 202005;

int n;
int a[MAXN];
int b[MAXN];
int mu[MAXN];

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++b[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) que.push(-i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[a[i]] > 1) {
            int t = -que.top();
            if (mu[a[i]]) {
                ++ans;
                --b[a[i]];
                a[i] = t;
                que.pop();
            } else {
                if (t < a[i]) {
                    --b[a[i]];
                    a[i] = t;
                    ++ans;
                    que.pop();
                } else {
                    mu[a[i]] = 1;
                }
            }

        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        printf("%d%s", a[i], i + 1 == n ? "\n" : " ");
    }
    return 0;
}
