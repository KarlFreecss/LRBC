#include<bits/stdc++.h>

using namespace std;

int check(const vector<int>& a, const int x, const set<int>& S){
    for (int i = 0; i < a.size(); ++i) if (S.count(a[i] + x)) return 0;
    return 1;
}

const int MAXN = 2e6+6;

bool S[MAXN];

void work(){
    int n;
    scanf("%d", &n);
    memset(S, 0, sizeof(S));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        a[i] = t;
    }
    int m = 0;
    puts("YES");
    for (int i = 1;; ++i){
        if (S[i]) continue;
        for (int k = 0; k < a.size(); ++k) {
            for (int l = 0; l < k; ++l) {
                S[i + abs(a[k] - a[l])] = 1;
            }
        }
        ++m;
        printf("%d", i);
        if (m == n) {
            printf("\n");
            return;
        } else {
            putchar(' ');
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        work();
    }
    return 0;
}
